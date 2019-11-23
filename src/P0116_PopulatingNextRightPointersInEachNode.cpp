//
// Created by yongpu on 2019/11/23 14:28.
//

#include "P0116_PopulatingNextRightPointersInEachNode.h"

/**
 * 题目：填充每个节点的下一个右侧节点指针
 * 描述：填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL.
 * 思路：每次将一整列连通，然后递归遍历左右子树.
 * 备注：记住思路
 */

/**
 *            1
 *         /    \
 *       2       3
 *     /  \     / \
 *    4    5   6   7
 *       一次循环
 *
 *            1
 *         /    \
 *       2 ————— 3
 *     /  \     / \
 *    4    5 ——6   7
 */

Node *P0116_PopulatingNextRightPointersInEachNode::connect(Node *root) {
    if (root == nullptr) {
        return root;
    }

    Node *left = root->left;
    Node *right = root->right;

    // 每次将一整列连通
    while (left) {
        left->next = right;

        left = left->right;     // 左节点的右孩子
        right = right->left;    // 右节点的左孩子
    }

    connect(root->left);
    connect(root->right);
    return root;
}

int P0116_PopulatingNextRightPointersInEachNode::test() {
    Node *t1 = new Node(1, nullptr, nullptr, nullptr);
    Node *t2 = new Node(2, nullptr, nullptr, nullptr);
    Node *t3 = new Node(3, nullptr, nullptr, nullptr);
    Node *t4 = new Node(4, nullptr, nullptr, nullptr);
    Node *t5 = new Node(5, nullptr, nullptr, nullptr);
    Node *t6 = new Node(6, nullptr, nullptr, nullptr);
    Node *t7 = new Node(7, nullptr, nullptr, nullptr);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    Node *root = t1;

    root = connect(root);

    return 0;
}
