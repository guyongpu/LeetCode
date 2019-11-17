//
// Created by yongpu on 2019/11/17 13:28.
//

#include "P0094_BinaryTreeInorderTraversal.h"

/**
 * 题目：二叉树的中序遍历
 * 描述：给定一个二叉树，返回它的中序遍历.
 * 思路：递归比较容易实现，迭代用栈实现，不断将左节点入栈，左节点为空是出栈并访问val，然后开始遍历右节点.
 * 备注：递归+迭代
 */


// 递归方法
void inorderTraversal_sub1(vector<int> &result, TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    if (root->left) {
        inorderTraversal_sub1(result, root->left);
    }
    result.push_back(root->val);
    if (root->right) {
        inorderTraversal_sub1(result, root->right);
    }
}

// 迭代方法
void inorderTraversal_sub2(vector<int> &result, TreeNode *root) {
    stack<TreeNode *> NodeStk;
    TreeNode *tNode = root;
    while (tNode || NodeStk.empty() == false) {
        while (tNode) {
            NodeStk.push(tNode);
            tNode = tNode->left;
        }
        TreeNode *temp = NodeStk.top();
        NodeStk.pop();
        result.push_back(temp->val);
        tNode = temp->right;
    }
}

vector<int> P0094_BinaryTreeInorderTraversal::inorderTraversal(TreeNode *root) {


    // 1.递归方法
    vector<int> result1;
    inorderTraversal_sub1(result1, root);

    // 2.迭代方法
    vector<int> result2;
    inorderTraversal_sub2(result2, root);


    return result2;
}

int P0094_BinaryTreeInorderTraversal::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(7);

    /**
     *            1
     *          /  \
     *         2    3
     *       /  \  /  \
     *      4   5 6    7
     */


    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    TreeNode *root = t1;

    vector<int> result = inorderTraversal(root);
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;


    return 0;
}
