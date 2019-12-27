//
// Created by yongpu on 2019/12/27 15:23.
//

#include "P0144_BinaryTreePreorderTraversal.h"

/**
 * 题目：二叉树的前序遍历
 * 描述：给定一个二叉树，返回它的前序遍历.
 * 思路：方法1.递归方法；方法2.非递归，使用栈实现，先插入右节点，再插入左节点.
 * 备注：掌握递归和非递归
 */


// 方法1.递归
void preorderTraversal_sub(TreeNode *root, vector<int> &result) {
    if (root) {
        result.push_back(root->val);
    } else {
        return;
    }

    preorderTraversal_sub(root->left, result);
    preorderTraversal_sub(root->right, result);
}

vector<int> P0144_BinaryTreePreorderTraversal::preorderTraversal_1(TreeNode *root) {
    if (root == nullptr) {
        return vector<int>();
    }

    vector<int> result;

    preorderTraversal_sub(root, result);

    return result;
}

/******************************************************************************/

// 方法2.非递归
vector<int> P0144_BinaryTreePreorderTraversal::preorderTraversal_2(TreeNode *root) {
    if (root == nullptr) {
        return vector<int>();
    }

    vector<int> result;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);

        // 先插入右节点
        if (node->right) {
            st.push(node->right);
        }
        // 先插入左节点
        if (node->left) {
            st.push(node->left);
        }
    }
    return result;
}

int P0144_BinaryTreePreorderTraversal::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(7);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    vector<int> result = preorderTraversal_2(t1);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
