//
// Created by yongpu on 2019/9/29.
//

#ifndef LEETCODE_P0000_COMMONHEAD_H
#define LEETCODE_P0000_COMMONHEAD_H

//单链表子节点
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {};
};

//二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 完美二叉树节点 p116
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

#endif //LEETCODE_P0000_COMMONHEAD_H
