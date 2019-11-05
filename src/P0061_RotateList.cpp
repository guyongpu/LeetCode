//
// Created by yongpu on 2019/11/5 9:27.
//

#include "P0061_RotateList.h"

/**
 * 题目：旋转链表
 * 描述：给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数.
 * 思路：方法1. 将BA = AB中将B尾指针与A的头指针连接；方法2.采用BA = (A^T  B^T)^T的方法.
 * 备注：优先采用方法1，方法2更适用于数组旋转操作.
 */



//方法1. 将BA = AB中将B尾指针与A的头指针连接
ListNode *P0061_RotateList::rotateRight_1(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // BA = (A^T + B^T)^T

    ListNode *node = head;  //计算链表长度
    int len = 0;
    while (node) {
        len++;
        node = node->next;
    }

    k = k % len;
    if (k == 0) {           //意味着不用位移，直接返回head即可
        return head;
    }

    int len1 = len - k;     // 第一段长度
    int len2 = k;           // 第二段长度

    // 定位 [node1_start,node1_end]
    ListNode *node1_start = head;
    ListNode *node1_end = node1_start;
    while (len1 > 1) {
        node1_end = node1_end->next;
        len1--;
    }

    // 定位 [node2_start,node2_end]
    ListNode *node2_start = node1_end->next;
    ListNode *node2_end = node2_start;
    while (len2 > 1) {
        node2_end = node2_end->next;
        len2--;
    }

    // 开始拼接
    // [node2_start,node2_end] 接 [node1_start,node1_end]
    node2_end->next = node1_start;
    node1_end->next = nullptr;

    ListNode *newHead = node2_start;
    return newHead;
}

// 方法2.采用BA = (A^T  B^T)^T的方法
ListNode *P0061_RotateList::rotateRight_2(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // BA = (A^T + B^T)^T

    ListNode *node = head;  //计算链表长度
    int len = 0;
    while (node) {
        len++;
        node = node->next;
    }

    k = k % len;
    if (k == 0) {           //意味着不用位移，直接返回head即可
        return head;
    }

    int len1 = len - k;     // 第一段长度
    int len2 = k;           // 第二段长度

    // BA = (A^T + B^T)^T
    ListNode *NextPart = nullptr;
    // 第一段 A
    ListNode *node_start1 = nullptr, *node_end1 = nullptr;
    node_start1 = head;
    node_end1 = head;
    while (len1 > 1) {
        node_end1 = node_end1->next;
        len1--;
    }
    NextPart = node_end1->next;     // B的起点
    ListNode *part1 = reverseList(node_start1, node_end1);

    // 第二段 B
    ListNode *node_start2 = NextPart;
    ListNode *node_end2 = NextPart;
    while (len2 > 1) {
        node_end2 = node_end2->next;
        len2--;
    }
    NextPart = node_start2;
    ListNode *part2 = reverseList(node_start2, node_end2);

    node_start1->next = part2;      // 连接A^T和B^T

    // 第三段 (A^T B^T)^T
    ListNode *node_start3 = part1;
    ListNode *node_end3 = NextPart;
    ListNode *part3 = reverseList(node_start3, node_end3);
    node_start3->next = nullptr;

    ListNode *newHead = part3;
    return newHead;
}

// 反转 node_start-node_end 之间的链表
ListNode *P0061_RotateList::reverseList(ListNode *node_start, ListNode *node_end) {
    ListNode *nodePre = nullptr, *nodeCurr = nullptr, *nodeNext = nullptr;
    nodePre = nullptr;
    nodeCurr = node_start;
    nodeNext = node_start->next;
    while (nodeCurr && nodePre != node_end) {
        nodeCurr->next = nodePre;

        nodePre = nodeCurr;
        nodeCurr = nodeNext;
        if (nodeNext) {
            nodeNext = nodeNext->next;
        }
    }
    ListNode *head = nodePre;
    return head;
}

int P0061_RotateList::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    ListNode *head = p1;

    head = rotateRight_1(head, 8);
    ListNode *node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}
