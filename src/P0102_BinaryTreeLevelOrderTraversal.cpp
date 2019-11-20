//
// Created by yongpu on 2019/11/20 16:32.
//

#include "P0102_BinaryTreeLevelOrderTraversal.h"

/**
 * 题目：二叉树的层次遍历
 * 描述：给定一个二叉树，返回其按层次遍历的节点值（即逐层地，从左到右访问所有节点).
 * 思路：一次遍历每一层，使用 tempNodes 保存下一层的节点，然后将 tempNodes 赋值给 Nodes，迭代遍历.
 * 备注：也可以改为用队列
 */

vector<vector<int>> P0102_BinaryTreeLevelOrderTraversal::levelOrder(TreeNode *root) {
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

    return result;
}

int P0102_BinaryTreeLevelOrderTraversal::test() {
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
    vector<vector<int>> result = levelOrder(root);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
