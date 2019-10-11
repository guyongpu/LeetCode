//
// Created by yongpu on 2019/10/11 9:15.
//

#include "P0160_IntersectionOfTwoLinkedLists.h"

/**
 * 题目：相交链表
 * 描述：找到两个单链表相交的起始节点.
 * 思路：先判断两个链表的长度，然后长的先走几步，接着一起走，第一次相遇就是相交的起始节点.
 * 备注：常见题
 */

ListNode *P0160_IntersectionOfTwoLinkedLists::getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    //计算 ListA 长度
    ListNode *pNodeA = headA;
    int lenA = 0;
    while (pNodeA) {
        lenA++;
        pNodeA = pNodeA->next;
    }

    //计算 ListB 长度
    ListNode *pNodeB = headB;
    int lenB = 0;
    while (pNodeB) {
        lenB++;
        pNodeB = pNodeB->next;
    }

    pNodeA = headA;
    pNodeB = headB;

    if (lenA > lenB) { // ListA 长，则 ListA 先走
        int step = lenA - lenB;
        while (step--) {
            pNodeA = pNodeA->next;
        }
    }

    if (lenB > lenA) { // ListB 长，则 ListB 先走
        int step = lenB - lenA;
        while (step--) {
            pNodeB = pNodeB->next;
        }
    }

    //开始一起走
    ListNode *resNode = nullptr;
    while (pNodeA && pNodeB) {
        if (pNodeA == pNodeB) {
            resNode = pNodeA;
            break;
        }
        pNodeA = pNodeA->next;
        pNodeB = pNodeB->next;
    }

    return resNode;
}

int P0160_IntersectionOfTwoLinkedLists::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);
    ListNode *p8 = new ListNode(8);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    ListNode *headA = p1;
    ListNode *headB = p5;

    ListNode *resNode = getIntersectionNode(headA, headB);
    if (resNode) {
        cout << resNode->val << endl;
    } else {
        cout << "nullptr" << endl;
    }

    return 0;
}
