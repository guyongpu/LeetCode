//
// Created by yongpu on 2019/12/26 20:17.
//

#include "P0141_LinkedListCycle.h"

/**
 * 题目：环形链表
 * 描述：给定一个链表，判断链表中是否有环
 * 思路：方法1.使用map或者set，存储并检查是否重复访问；方法2.使用快慢指针，慢指针走一步，快指针走两步，重合则有环.
 * 备注：掌握两种方法.
 */

bool P0141_LinkedListCycle::hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode *fast = head->next;
    ListNode *low = head;

    while (fast) {
        if (fast == low) {
            return true;
        }
        if (fast->next == nullptr) {
            break;
        } else {
            fast = fast->next->next;
            low = low->next;
        }
    }

    return false;
}

int P0141_LinkedListCycle::test() {
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
    p6->next = p5;

    ListNode *head = p1;
    cout << hasCycle(p1) << endl;

    return 0;
}
