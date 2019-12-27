//
// Created by yongpu on 2019/12/27 20:29.
//

#include "P0230_KthSmallestElementInA_BST.h"

/**
 * 题目：二叉搜索树中第K小的元素
 * 描述：给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素.
 * 思路：方法1.递归法进行中序遍历；方法2.非递归中序遍历.
 * 备注：掌握方法1和2
 */

void kthSmallest_sub(TreeNode *root, int &result, int &index, int k) {
    if (root == nullptr) {
        return;
    }

    kthSmallest_sub(root->left, result, index, k);

    index++;
    if (index == k) {
        result = root->val;
        return;
    } else if (index > k) {
        return;
    }

    kthSmallest_sub(root->right, result, index, k);
}

int P0230_KthSmallestElementInA_BST::kthSmallest_1(TreeNode *root, int k) {
    int result = 0;
    int index = 0;
    kthSmallest_sub(root, result, index, k);
    return result;
}

int P0230_KthSmallestElementInA_BST::kthSmallest_2(TreeNode *root, int k) {
    stack<TreeNode *> st;
    TreeNode *node = root;

    int index = 0;
    while (node || !st.empty()) {
        // 一直遍历到左子树最下边，边遍历边保存根节点到栈中
        while (node) {
            st.push(node);
            node = node->left;
        }

        // 当p为空时，说明已经到达左子树最下边，这时需要出栈了
        if (!st.empty()) {
            node = st.top();
            st.pop();
            index++;
            if (index == k) {
                return node->val;
            }
            node = node->right;
        }
    }

    return 0;
}


int P0230_KthSmallestElementInA_BST::test() {
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(2);

    p1->left = p2;
    p1->right = p3;

    p2->right = p4;

    cout << kthSmallest_1(p1, 1) << endl;
    cout << kthSmallest_2(p1, 1) << endl;

    return 0;
}
