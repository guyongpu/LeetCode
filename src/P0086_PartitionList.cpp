//
// Created by yongpu on 2019/11/12 9:40.
//

#include "P0086_PartitionList.h"

/**
 * 题目：分隔链表
 * 描述：给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前.
 * 思路：建立两个链表头sml和big，将原链表小于x与大于等于x的两类节点分别连接到sml和big上，再连接sml和big即可.
 * 备注：双指针法
 */

ListNode *P0086_PartitionList::partition(ListNode *head, int x) {
    ListNode *head_big = new ListNode(0);
    ListNode *head_sml = new ListNode(0);

    ListNode *pNode = head;
    ListNode *pNode_sml = head_sml;     // 小于x的链表
    ListNode *pNode_big = head_big;     // 大于等于x的链表


    // 小于x -- 大于等于x
    while (pNode) {
        if (pNode->val < x) {           // 添加到head_sml链表
            pNode_sml->next = pNode;

            pNode = pNode->next;
            pNode_sml = pNode_sml->next;
            pNode_sml->next = nullptr;
        } else {                        // 添加到head_big链表
            pNode_big->next = pNode;

            pNode = pNode->next;
            pNode_big = pNode_big->next;
            pNode_big->next = nullptr;
        }
    }
    // 将head_sml 与 head_big连接，顺序：小于 -- 大于等于
    pNode_sml->next = head_big->next;

    return head_sml->next;
}

int P0086_PartitionList::test() {
    ListNode *p1 = new ListNode(9);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(1);
    ListNode *p4 = new ListNode(8);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(7);
    ListNode *p7 = new ListNode(3);
    ListNode *p8 = new ListNode(6);
    ListNode *p9 = new ListNode(4);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;
    p8->next = p9;

    ListNode *head = p1;

    head = partition(head, 5);
    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    return 0;
}
