//
// Created by yongpu on 2019/10/16 10:15.
//

#include "P0019_RemoveNthNodeFromEndOfList.h"

/**
 * 题目：删除链表的倒数第N个节点
 * 描述：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点.
 * 思路：用双指针实现，pLast指针先走n步，然后pFront再一起走，直到pLast.next=nullptr,另外注意删除头节点的处理.
 * 备注：双指针+头节点处理.
 */

ListNode *P0019_RemoveNthNodeFromEndOfList::removeNthFromEnd(ListNode *head, int n) {
    ListNode *pFront, *pLast;
    pFront = head;
    pLast = head;
    int step = 0;
    while (pLast) {
        step++;
        pLast = pLast->next;
        if(step == n){
            break;
        }
    }
    if(pLast == nullptr){   //说明要求删除头节点
        head = head->next;
    }
    else{
        while(pLast->next){
            pFront = pFront->next;
            pLast = pLast->next;
        }
        pFront->next = pFront->next->next;
    }

    return head;
}

int P0019_RemoveNthNodeFromEndOfList::test() {
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
    head = removeNthFromEnd(head, 1);

    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;
    return 0;
}
