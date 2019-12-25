//
// Created by yongpu on 2019/12/25 19:57.
//

#include "P0234_PalindromeLinkedList.h"

/**
 * 题目：回文链表
 * 描述：请判断一个链表是否为回文链表，要求 O(n) 时间复杂度和 O(1) 空间复杂度.
 * 思路：法1.将链表计算长度，并将后半部分存入vector或栈中，然后出栈比较；法2.使用快慢指针找到中点，然后翻转后半部分，最后遍历两部分比较.
 * 备注：重要题目，注意复习.
 */

bool P0234_PalindromeLinkedList::isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode *low = head;
    ListNode *fast = head;

    while (fast->next) {
        if (fast->next->next) {
            fast = fast->next->next;
            low = low->next;
        } else {
            fast = fast->next;
        }
    }

    // 此时，low指向终点，fast指向尾节点
    // 翻转low之后的链表，即后半部分链表
    ListNode *pre = nullptr;
    ListNode *cur = low->next;
    ListNode *next = nullptr;

    while (cur) {
        next = cur->next;
        cur->next = pre;

        pre = cur;
        cur = next;
    }

    ListNode *head_1 = head;    // 前半部分
    ListNode *head_2 = pre;     // 后半部分

    while (head_1 && head_2) {
        if (head_1->val != head_2->val) {
            return false;
        }
        head_1 = head_1->next;
        head_2 = head_2->next;
    }
    return true;
}

int P0234_PalindromeLinkedList::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(5);
    ListNode *p7 = new ListNode(4);
    ListNode *p8 = new ListNode(3);
    ListNode *p9 = new ListNode(2);
    ListNode *p10 = new ListNode(1);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;
    p8->next = p9;
    p9->next = p10;

    ListNode *head = p1;

    cout << isPalindrome(head) << endl;

    return 0;
}
