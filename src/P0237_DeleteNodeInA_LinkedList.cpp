//
// Created by yongpu on 2019/12/28 21:20.
//

#include "P0237_DeleteNodeInA_LinkedList.h"

/**
 * 题目：删除链表中的节点
 * 描述：请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点.
 * 思路：将当前节点的值改为下一个节点的值，然后当前节点指向下下个节点，如 A-B-C-D，删除B,则得到A-B(c.val)-D.
 * 备注：采用值复制的方法，转化为删除下一个节点
 */

void P0237_DeleteNodeInA_LinkedList::deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

int P0237_DeleteNodeInA_LinkedList::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    deleteNode(p4);

    return 0;
}
