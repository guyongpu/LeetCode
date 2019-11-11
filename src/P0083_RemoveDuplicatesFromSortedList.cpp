//
// Created by yongpu on 2019/11/11 10:46.
//

#include "P0083_RemoveDuplicatesFromSortedList.h"

/**
 * 题目：删除排序链表中的重复元素
 * 描述：给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次.
 * 思路：使用两个指针，pCurr指向当前新链表的最后一个节点，pNode为遍历节点，记得pCurr->next置空.
 * 备注：双指针法
 */

ListNode *P0083_RemoveDuplicatesFromSortedList::deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *newHead = new ListNode(0);

    ListNode *pCurr = head;
    ListNode *pNode = head->next;

    newHead->next = pCurr;
    pCurr->next = nullptr;              // pCurr->next记得置空,如{1,1}

    while (pNode) {
        if (pNode->val == pCurr->val) {
            pNode = pNode->next;
        } else {
            pCurr->next = pNode;

            pCurr = pCurr->next;
            pNode = pNode->next;

            pCurr->next = nullptr;      // pCurr->next记得置空
        }
    }

    return newHead->next;
}

int P0083_RemoveDuplicatesFromSortedList::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(5);
    ListNode *p7 = new ListNode(9);
    ListNode *p8 = new ListNode(9);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;

    ListNode *head = p1;
    head = deleteDuplicates(head);

    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;

    return 0;
}
