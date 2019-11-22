//
// Created by yongpu on 2019/11/22 13:44.
//

#include "P0111_MinimumDepthOfBinaryTree.h"

/**
 * 题目：二叉树的最小深度
 * 描述：给定一个二叉树，找出其最小深度.
 * 思路：方法1.在计算树深度的基础上进行修改，如果叶子节点，则返回1，否则根据左右节点情况进一步递归；方法2.用层序遍历思想计算.
 * 备注：掌握方法1和方法2.
 */

// 方法1.计算树的深度
int P0111_MinimumDepthOfBinaryTree::minDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {  // root为叶子结点，返回1
        return 1;
    } else {
        if (root->left != nullptr && root->right != nullptr) {      // 左右节点都不为空，则结果在左右子树中
            return 1 + min(minDepth(root->left), minDepth(root->right));
        } else if (root->left != nullptr) {                         // 左不为空，右为空，则结果在右子树中
            return 1 + minDepth(root->left);
        } else {                                                    // 右为空，左不为空，则结果在左子树中
            return 1 + minDepth(root->right);
        }
    }
}

// 方法2.采用层序遍历思想
int P0111_MinimumDepthOfBinaryTree::minDepth_2(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    vector<TreeNode *> nodes = {root};

    int cnt = 0;
    while (nodes.size()) {
        cnt++;
        vector<TreeNode *> nodes_temp;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->left == nullptr && nodes[i]->right == nullptr) {
                nodes_temp.clear();
                break;
            }
            if (nodes[i]->left) {
                nodes_temp.push_back(nodes[i]->left);
            }
            if (nodes[i]->right) {
                nodes_temp.push_back(nodes[i]->right);
            }
        }
        nodes = nodes_temp;
    }
    return cnt;
}


int P0111_MinimumDepthOfBinaryTree::test() {
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    TreeNode *root = t1;
    cout << minDepth_2(root) << endl;
    return 0;
}
