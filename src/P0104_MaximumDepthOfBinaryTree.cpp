//
// Created by yongpu on 2019/11/20 17:16.
//

#include "P0104_MaximumDepthOfBinaryTree.h"

/**
 * 题目：二叉树的最大深度
 * 描述：给定一个二叉树，找出其最大深度.
 * 思路：root为空返回0，否则递归，返回1+max(左子树深度，右子树深度)。
 * 备注：深度递归DFS或者层序遍历BFS
 */

int P0104_MaximumDepthOfBinaryTree::maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));    // 递归，返回1+max(左子树深度，右子树深度)
}

int P0104_MaximumDepthOfBinaryTree::test() {
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

    cout << maxDepth(root) << endl;
    return 0;
}
