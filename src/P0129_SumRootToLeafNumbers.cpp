//
// Created by yongpu on 2019/12/3 19:58.
//

#include "P0129_SumRootToLeafNumbers.h"

/**
 * 题目：求根到叶子节点数字之和
 * 描述：给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字，计算从根到叶子节点生成的所有数字之和.
 * 思路：使用DFS深度优先搜索，当遇到叶子节点时将数据进行累加，最后返回即可.
 * 备注：DFS深度优先搜索
 */

void sumNumbers_sub(TreeNode *root, int temp, int &result) {
    if (root->left == nullptr && root->right == nullptr) {
        result = result + temp * 10 + root->val;
    }

    if (root->left) {
        sumNumbers_sub(root->left, temp * 10 + root->val, result);
    }

    if (root->right) {
        sumNumbers_sub(root->right, temp * 10 + root->val, result);
    }
}

int P0129_SumRootToLeafNumbers::sumNumbers(TreeNode *root) {
    if(root == nullptr){
        return 0;
    }
    int result = 0;
    int temp = 0;
    sumNumbers_sub(root, temp, result);

    return result;
}

int P0129_SumRootToLeafNumbers::test() {
    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(0);
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(1);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    TreeNode *root = t1;
    cout << sumNumbers(root) << endl;
    return 0;
}