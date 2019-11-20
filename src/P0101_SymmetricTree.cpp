//
// Created by yongpu on 2019/11/20 11:29.
//

#include "P0101_SymmetricTree.h"

/**
 * 题目：对称二叉树
 * 描述：给定一个二叉树，检查它是否是镜像对称的.
 * 思路：对左右节点分别进行递归遍历，判断是否相等.
 * 备注：常考题，注意复习
 */

bool isSymmetric_sub(TreeNode *lchild, TreeNode *rchild) {
    if (lchild == nullptr || rchild == nullptr) {
        if (lchild == nullptr && rchild == nullptr) {
            return true;
        } else {
            return false;
        }
    }
    if (lchild->val == rchild->val) {
        bool flag1 = isSymmetric_sub(lchild->left, rchild->right);
        bool flag2 = isSymmetric_sub(lchild->right, rchild->left);
        if (flag1 && flag2) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool P0101_SymmetricTree::isSymmetric(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    bool result = isSymmetric_sub(root->left, root->right);
    return result;
}

int P0101_SymmetricTree::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(4);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    TreeNode *root = t1;

    cout << isSymmetric(root) << endl;
    return 0;
}
