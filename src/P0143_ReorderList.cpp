//
// Created by yongpu on 2019/12/27 14:47.
//

#include "P0143_ReorderList.h"

/**
 * 题目：重排链表
 * 描述：给定一个单链表，改为前后交替的单链表.
 * 思路：方法1.使用双端队列，然后依次出队并连接即可；方法2.(1)将链表分为左右两部分；(2)将后部分翻转；（3）将左右链表交替遍历并连接.
 * 备注：掌握方法1和方法2
 */

void P0143_ReorderList::reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    ListNode *NewHead = new ListNode(0);

    deque<ListNode *> node_que;
    ListNode *node = head;
    while (node) {
        node_que.push_back(node);
        node = node->next;
    }

    node = NewHead;
    ListNode *p_front = nullptr;
    ListNode *p_tail = nullptr;
    while (!node_que.empty()) {
        p_front = node_que.front();
        node_que.pop_front();
        node->next = p_front;
        node = node->next;

        if (!node_que.empty()) {
            p_tail = node_que.back();
            node_que.pop_back();
            node->next = p_tail;
            node = node->next;
        }

    }
    node->next = nullptr;
    p_front = nullptr;
    p_tail = nullptr;
}

int P0143_ReorderList::test() {
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
    reorderList(head);
    return 0;
}
