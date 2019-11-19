//
// Created by yongpu on 2019/11/18 21:24.
//

#include "P0098_ValidateBinarySearchTree.h"

/**
 * 题目：验证二叉搜索树
 * 描述：给定一个二叉树，判断其是否是一个有效的二叉搜索树.
 * 思路：使用中序遍历思想进行验证，中序遍历应该是一个严格递归序列，否则返回false；方法1.递归；方法2.迭代.
 * 备注：递归+迭代
 */

// 方法1.递归方法实现中序遍历
bool P0098_ValidateBinarySearchTree::isValidBST_1(TreeNode *root) {
    bool result = true;

    if (root == nullptr) {
        return result;
    }
    int index = 0;
    int PrevNum = 0;

    isValidBST_sub(result, index, PrevNum, root);

    return result;
}

void P0098_ValidateBinarySearchTree::isValidBST_sub(bool &result, int &index, int &PrevNum, TreeNode *root) {
    if (root == nullptr || result == false) {
        return;
    }
    if (root->left) {
        isValidBST_sub(result, index, PrevNum, root->left);
    }

    if (result == false) {
        return;
    }
    /* 访问数据 */
    if (index == 0) {
        index++;
        PrevNum = root->val;
    } else {
        index++;
        if (PrevNum < root->val) {
            result = true;
        } else {
            result = false;
            return;
        }
        PrevNum = root->val;
    }
    cout << root->val << " ";

    if (root->right) {
        isValidBST_sub(result, index, PrevNum, root->right);
    }
}

/***********************************************************************/

// 方法2迭代递归遍历
bool P0098_ValidateBinarySearchTree::isValidBST_2(TreeNode *root) {
    stack<TreeNode *> treeStack;

    int index = 0;
    int cmpNum = 0;

    while (treeStack.empty() == false || root != nullptr) {
        while (root != nullptr) {
            treeStack.push(root);
            root = root->left;
        }
        root = treeStack.top();
        treeStack.pop();

        if (index == 0) {
            index = 1;
            cmpNum = root->val;
        } else {
            if (cmpNum >= root->val) {
                return false;
            }
            cmpNum = root->val;
        }
        root = root->right;
    }
    return true;
}


int P0098_ValidateBinarySearchTree::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(7);
    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(8);

    t1->left = t2;
    /*
    t1->right = t3;

    t3->left = t4;
    t3->right = t5;*/

    TreeNode *root = t1;
   // cout << isValidBST_1(root) << endl;
    cout << isValidBST_2(root) << endl;

    return 0;
}
