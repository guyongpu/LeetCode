//
// Created by yongpu on 2019/10/24 10:47.
//

#include "P0199_BinaryTreeRightSideView.h"

/**
 * 题目：二叉树的右视图
 * 描述：给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值.
 * 思路：采用层序遍历思想，把每层的最右节点保存到result中即可.
 * 备注：掌握层序遍历.
 */

vector<int> P0199_BinaryTreeRightSideView::rightSideView(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    vector<TreeNode *> nodeVec = {root};
    while (nodeVec.size() > 0) {
        int node_size = nodeVec.size();
        /*
        //输出当前层的所有节点
        for (int i = 0; i < node_size; i++) {
            cout << nodeVec[i]->val << " ";
        }
        cout << endl;
         */
        result.push_back(nodeVec[node_size-1]->val);

        vector<TreeNode *> nodeVec_child;
        for (int i = 0; i < nodeVec.size(); i++) {
            if (nodeVec[i]->left)
                nodeVec_child.push_back(nodeVec[i]->left);
            if (nodeVec[i]->right)
                nodeVec_child.push_back(nodeVec[i]->right);
        }
        nodeVec = nodeVec_child;
    }

    return result;
}

int P0199_BinaryTreeRightSideView::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);

    t1->left = t2;
    t1->right = t3;

    t2->right = t5;
    t3->right = t4;

    t5->left = t6;

    TreeNode *root = t1;

    vector<int> result = rightSideView(root);
    int num = result.size();
    for (int i = 0; i < num; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

