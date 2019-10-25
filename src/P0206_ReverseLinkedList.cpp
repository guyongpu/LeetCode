//
// Created by yongpu on 2019/10/25 10:40.
//

#include "P0206_ReverseLinkedList.h"

/**
 * 题目：反转链表
 * 描述：反转一个单链表.
 * 思路：定义nodePrev,nodeCurr,nodeNext，每次将nodeCurr->nodePrev，遍历链表，nodePrev为新头节点.
 * 备注：重要的题目.
 */

ListNode *P0206_ReverseLinkedList::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *nodePrev = nullptr;
    ListNode *nodeCurr = head;
    ListNode *nodeNext = head->next;


    while (nodeCurr) {
        nodeCurr->next = nodePrev;

        nodePrev = nodeCurr;
        nodeCurr = nodeNext;
        if (nodeNext) {         //防止nodeCurr为空，而nodeCurr->next不存在的情况.
            nodeNext = nodeNext->next;
        }
    }
    ListNode *newHead = nodePrev;

    return newHead;
}

int P0206_ReverseLinkedList::test() {
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

    head = reverseList(head);

    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << "  ";
        pNode = pNode->next;
    }
    cout << endl;
    return 0;
}
