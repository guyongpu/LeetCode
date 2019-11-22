//
// Created by yongpu on 2019/11/22 15:54.
//

#include "P0113_PathSumII.h"

/**
 * 题目：路径总和II
 * 描述：给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径.
 * 思路：采用DFS递归，当遇到叶子节点时，判断是否满足要求，非叶子节点则进行递归.
 * 备注：也可以采用BFS层序遍历实现.
 */

void P0113_PathSumII::dfs(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &result) {

    // 叶子节点
    if (root && root->left == nullptr && root->right == nullptr) {
        if (sum == root->val) {
            path.push_back(root->val);
            result.push_back(path);
        }
        return;
    }

    // 非叶子节点
    if (root) {
        sum = sum - root->val;
        path.push_back(root->val);
        if (root->left) {
            dfs(root->left, sum, path, result);
        }
        if (root->right) {
            dfs(root->right, sum, path, result);
        }
    }
}

vector<vector<int>> P0113_PathSumII::pathSum(TreeNode *root, int sum) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(root, sum, path, result);
    return result;
}

int P0113_PathSumII::test() {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(8);
    TreeNode *t4 = new TreeNode(11);
    TreeNode *t5 = new TreeNode(13);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(2);
    TreeNode *t9 = new TreeNode(5);
    TreeNode *t10 = new TreeNode(1);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;

    t3->left = t5;
    t3->right = t6;

    t4->left = t7;
    t4->right = t8;

    t6->left = t9;
    t6->right = t10;

    TreeNode *root = t1;
    vector<vector<int>> result = pathSum(root, 22);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
