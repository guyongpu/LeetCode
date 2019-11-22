//
// Created by yongpu on 2019/11/22 15:17.
//

#include "P0112_PathSum.h"

/**
 * 题目：路径总和
 * 描述：给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和.
 * 思路：DFS深度优先搜索，当为叶子节点时，判断sum=root.val，等于为true，否则为false；非叶子节点，则递归判断左右子树.
 * 备注：也可以用BFS，即层序遍历思想.
 */

bool P0112_PathSum::hasPathSum(TreeNode *root, int sum) {
    // 叶子节点
    if (root && root->left == nullptr && root->right == nullptr) {
        if(sum == root->val){
            return true;
        } else{
            return false;
        }
    }

    // 非叶子节点
    if (root != nullptr) {
        sum = sum - root->val;
        if (hasPathSum(root->left, sum) || hasPathSum(root->right, sum)) {
            return true;
        }
    }
    return false;
}

int P0112_PathSum::test() {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(8);
    TreeNode *t4 = new TreeNode(11);
    TreeNode *t5 = new TreeNode(13);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(2);
    TreeNode *t9 = new TreeNode(1);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;

    t3->left = t5;
    t3->right = t6;

    t4->left = t7;
    t4->right = t8;

    t6->right = t9;

    TreeNode *root = t1;
    cout << hasPathSum(root, 22) << endl;
    return 0;
}
