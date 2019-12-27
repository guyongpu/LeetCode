//
// Created by yongpu on 2019/12/27 16:50.
//

#include "P0145_BinaryTreePostorderTraversal.h"

/**
 * 题目：二叉树的后序遍历
 * 描述：给定一个二叉树，返回它的后序遍历.
 * 思路：方法1.递归做法；方法2.BFS宽搜+逆序 = 后序
 * 备注：掌握方法1和2
 */

// 方法1.递归
void postorderTraversal_sub(TreeNode *root, vector<int> &result) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal_sub(root->left, result);

    postorderTraversal_sub(root->right, result);

    result.push_back(root->val);
}

vector<int> P0145_BinaryTreePostorderTraversal::postorderTraversal_1(TreeNode *root) {
    if (root == nullptr) {
        return vector<int>();
    }

    vector<int> result;

    postorderTraversal_sub(root, result);
    return result;
}

/*****************************************************************************************/
// 方法2.非递归
// 宽搜+逆序输出 = 后序遍历
vector<int> P0145_BinaryTreePostorderTraversal::postorderTraversal_2(TreeNode *root) {
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

        if (node->left) {
            st.push(node->left);
        }

        if (node->right) {
            st.push(node->right);
        }
    }
    // 逆序
    reverse(result.begin(), result.end());
    return result;
}

int P0145_BinaryTreePostorderTraversal::test() {
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

    vector<int> result = postorderTraversal_1(t1);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}

