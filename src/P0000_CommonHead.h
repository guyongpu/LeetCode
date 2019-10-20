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

#endif //LEETCODE_P0000_COMMONHEAD_H
