//
// Created by yongpu on 2019/11/14 21:08.
//

#include "P0092_ReverseLinkedListII.h"

/**
 * 题目：反转链表II
 * 描述：反转从位置 m 到 n 的链表。请使用一趟扫描完成反转.
 * 思路：1.先找到翻转的开始位置；2.开始翻转并计数；3.前中后三部分进行拼接.
 * 备注：要仔细，pPrev，pCurr，pNext三个指针
 */

ListNode *P0092_ReverseLinkedListII::reverseBetween(ListNode *head, int m, int n) {
    if (head == nullptr || head->next == nullptr || m == n) {   // 如果为空或只有一个节点或m==n，则直接返回head
        return head;
    }

    ListNode *newHead = new ListNode(0);    // 虚拟头节点
    ListNode *pNewNode = newHead;

    int index = 0;                             // 计数器
    ListNode *pNode = head;
    while (pNode) {                             // 找开始位置
        if (index == m - 1) {
            //开始翻转,起始节点为 pNode
            ListNode *pPrev = pNode;            // 上一个
            ListNode *pCurr = pNode->next;      // 当前
            ListNode *pNext = nullptr;          // 下一个

            //方法： 原本：pPrev -> pCurr -> pNext   修改：pPrev <- pCurr  pNext

            pPrev->next = nullptr;              // 翻转后的链表尾
            index++;
            while (index < n && pCurr) {        // 翻转操作
                pNext = pCurr->next;
                pCurr->next = pPrev;

                pPrev = pCurr;
                pCurr = pNext;
                index++;
            }
            // 对3个部分进行拼接
            pNewNode->next = pPrev;     // 前部分尾 + 翻转部分的头
            pNode->next = pNext;        // 翻转部分尾 + 后部分头
            break;
        } else {
            pNewNode->next = pNode;
            pNewNode = pNewNode->next;
            pNode = pNode->next;

            pNewNode->next = nullptr;
            index++;
        }
    }

    return newHead->next;
}

int P0092_ReverseLinkedListII::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    ListNode *head = p1;

    head = reverseBetween(head, 2, 4);

    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }

    return 0;
}
