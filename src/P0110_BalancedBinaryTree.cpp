//
// Created by yongpu on 2019/11/22 11:05.
//

#include "P0110_BalancedBinaryTree.h"

/**
 * 题目：平衡二叉树
 * 描述：给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 思路：方法1.采用后序遍历思想，进行一次DFS即可得出结果；方法2.对每个结点调用的求深度的函数。
 * 备注：掌握方法1和方法2
 */

// 方法1 采用后序遍历思想
bool P0110_BalancedBinaryTree::isBalanced_1(TreeNode *root) {
    int depth = 0;
    bool result = isBalanced_sub(root, depth);
    return result;
}

bool P0110_BalancedBinaryTree::isBalanced_sub(TreeNode *pRoot, int &depth) {
    if (pRoot == nullptr) {
        depth = 0;
        return true;
    }

    int depth_l = 0;
    int depth_r = 0;

    bool result_l = true;
    bool result_r = true;

    if (pRoot->left) {
        result_l = isBalanced_sub(pRoot->left, depth_l);
    }
    if (pRoot->right) {
        result_r = isBalanced_sub(pRoot->right, depth_r);
    }

    if (result_l && result_r) {
        if (abs(depth_l - depth_r) <= 1) {
            depth = 1 + max(depth_l, depth_r);
            return true;
        }
    }
    return false;
}

/*****************************************************************************/
// 方法2 对每个结点进行递归求深度
bool P0110_BalancedBinaryTree::isBalanced_2(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    if (abs(TreeDepth(root->left) - TreeDepth(root->right)) <= 1) {
        if (isBalanced_2(root->left) && isBalanced_2(root->right)) {
            return true;
        }
    }
    return false;
}

int P0110_BalancedBinaryTree::TreeDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(TreeDepth(root->left), TreeDepth(root->right));
}


int P0110_BalancedBinaryTree::test() {
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);

    t1->left = t2;
    t1->right = t3;

    t3->left = t4;
    t3->right = t5;

    TreeNode *root = t1;
    cout << isBalanced_2(root) << endl;
    return 0;
}
