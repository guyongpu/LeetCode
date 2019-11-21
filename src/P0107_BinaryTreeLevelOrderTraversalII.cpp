//
// Created by yongpu on 2019/11/21 8:52.
//

#include "P0107_BinaryTreeLevelOrderTraversalII.h"

/**
 * 题目：二叉树的层次遍历II
 * 描述：给定一个二叉树，返回其节点值自底向上的层次遍历。(即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历).
 * 思路：与普通层序遍历类似,在最后对result结果进行翻转即可。也可以先加入队列，然后再倒序访问队列.
 * 备注：熟练题目
 */

vector<vector<int>> P0107_BinaryTreeLevelOrderTraversalII::levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
        return result;
    }
    vector<TreeNode *> Nodes = {root};

    while (Nodes.size() > 0) {
        vector<int> valVec;
        for (int i = 0; i < Nodes.size(); i++) {
            valVec.push_back(Nodes[i]->val);
        }
        result.push_back(valVec);

        vector<TreeNode *> tempNodes;
        for (int i = 0; i < Nodes.size(); i++) {
            if (Nodes[i]->left) {
                tempNodes.push_back(Nodes[i]->left);
            }
            if (Nodes[i]->right) {
                tempNodes.push_back(Nodes[i]->right);
            }
        }
        Nodes = tempNodes;
    }
    reverse(result.begin(), result.end());
    return result;
}

int P0107_BinaryTreeLevelOrderTraversalII::test() {
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
    vector<vector<int>> result = levelOrderBottom(root);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
