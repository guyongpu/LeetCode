//
// Created by yongpu on 2019/12/27 10:59.
//

#include "P0142_LinkedListCycleII.h"

/**
 * 题目：环形链表II
 * 描述：给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null.
 * 思路：分为3步，1.判断是否有环并计步；2.开始找入口，fast先走step步；3.相遇的时候为入口
 * 备注：掌握步骤.
 */

ListNode *P0142_LinkedListCycleII::detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode *low = head;
    ListNode *fast = head->next;

    // 1.判断是否有环并计步
    int step = 1;
    bool flag = false;
    while (fast) {
        if (low == fast) {
            flag = true;
            break;
        }

        if (fast->next == nullptr) {
            return nullptr;
        }

        fast = fast->next->next;
        low = low->next;
        step++;
    }

    // 无环则返回nullptr
    if (flag == false) {
        return nullptr;
    }

    // 2.开始找入口，fast先走step步
    fast = head;
    low = head;
    // fast先走step步
    while (step--) {
        fast = fast->next;
    }

    // 3.相遇的时候为入口
    while (low != fast) {
        low = low->next;
        fast = fast->next;
    }

    return low;
}

int P0142_LinkedListCycleII::test() {
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
    p6->next = p1;

    ListNode *head = p1;
    cout << detectCycle(p1)->val << endl;

    return 0;
}
