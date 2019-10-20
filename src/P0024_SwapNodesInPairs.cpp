//
// Created by yongpu on 2019/10/18 15:57.
//

#include "P0024_SwapNodesInPairs.h"

/**
 * 题目：两两交换链表中的节点
 * 描述：给定一个链表，两两交换其中相邻的节点，并返回交换后的链表.
 * 思路：每次取两个节点进行交换，使后节点->前节点，并将前节点->tail
 * 备注：要仔细.
 */

ListNode *P0024_SwapNodesInPairs::swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *NewHead = new ListNode(0);

    ListNode *tail_prev = NewHead;  //创建一个虚拟头节点
    ListNode *p1 = head;            //前节点
    ListNode *p2 = head->next;      //后节点
    ListNode *pNode = nullptr;
    while (1) {
        pNode = p2->next;

        // 将后节点->前节点
        p2->next = p1;
        tail_prev->next = p2;

        // 将前节点->tail
        tail_prev = p1;             //将p1连接到尾节点
        tail_prev->next = nullptr;

        if (pNode && pNode->next) { //都不为空
            p1 = pNode;
            p2 = pNode->next;
        } else {
            if(pNode){              //剩余一个节点不为空
                tail_prev->next = pNode;
            }
            break;
        }

    }

    NewHead = NewHead->next;
    return NewHead;
}

int P0024_SwapNodesInPairs::test() {
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
    head = swapPairs(head);

    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;

    return 0;
}
