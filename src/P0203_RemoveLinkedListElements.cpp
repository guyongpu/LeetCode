//
// Created by yongpu on 2019/10/25 8:53.
//

#include "P0203_RemoveLinkedListElements.h"

/**
 * 题目：移除链表元素
 * 描述：删除链表中等于给定值 val 的所有节点.
 * 思路：方法1.创建一个虚拟头节点，并不断连接不为val的节点，注意要给new_pNode->next = nullptr；方法2.不创建头节点，其他与法1类似；方法3.存入vector中，再连接.
 * 备注：掌握三种方法.
 */

ListNode *P0203_RemoveLinkedListElements::removeElements(ListNode *head, int val) {
    ListNode *new_Head = new ListNode(0);
    ListNode *new_pNode = new_Head;
    ListNode *old_pNode = head;
    while (old_pNode) {
        if (old_pNode->val != val) {
            new_pNode->next = old_pNode;

            old_pNode = old_pNode->next;

            new_pNode = new_pNode->next;
            new_pNode->next = nullptr;      //令new_pNode->next为空
        } else {
            old_pNode = old_pNode->next;
        }
    }

    return new_Head->next;
}

int P0203_RemoveLinkedListElements::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(6);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);
    ListNode *p8 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;

    ListNode *head = p1;
    head = removeElements(head, 6);
    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;

    return 0;
}
