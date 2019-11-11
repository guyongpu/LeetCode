//
// Created by yongpu on 2019/11/11 9:56.
//

#include "P0082_RemoveDuplicatesFromSortedListII.h"

/**
 * 题目：删除排序链表中的重复元素II
 * 描述：给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现的数字.
 * 思路：使用三个指针，pPrev指向不重复的节点，pCurr指向当前待比较节点，pNode指向遍历节点，设置dupFlag标记，同时处理最后的dupFlag.
 * 备注：连接时要将pPrev->next置空
 */

ListNode *P0082_RemoveDuplicatesFromSortedListII::deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *newHead = new ListNode(0);     // 构造一个虚拟头节点
    ListNode *pNode = head->next;               // 遍历节点
    ListNode *pCurr = head;                     // 当前待比较元素
    ListNode *pPrev = newHead;                  // 上一个不重复的元素

    // 1-1-3-5-5-5-7

    bool dupFlag = false;
    while (pNode) {
        if (pNode->val == pCurr->val) {
            pNode = pNode->next;
            dupFlag = true;
        } else {
            if (dupFlag == false) {
                pPrev->next = pCurr;
                pCurr = pNode;

                pPrev = pPrev->next;
                pNode = pNode->next;

                pPrev->next = nullptr;          // 要将pPrev->next置空
            } else {
                pCurr = pNode;
                dupFlag = false;

                pNode = pNode->next;
            }
        }
    }

    if (dupFlag == false) {     // 如果最后一个不重复，则加入
        pPrev->next = pCurr;
    }

    return newHead->next;
}

int P0082_RemoveDuplicatesFromSortedListII::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(5);
    ListNode *p7 = new ListNode(7);
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
