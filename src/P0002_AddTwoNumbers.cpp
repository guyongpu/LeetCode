//
// Created by yongpu on 2019/9/29.
//

#include "P0002_AddTwoNumbers.h"

/**
 * 题目：两数相加
 * 描述：两个非空的链表用来表示两个非负的整数，将这两个数相加起来，则会返回一个新的链表来表示它们的和.
 * 思路：采用链表合并思想，1.当都不为空时，逐个合并；2.其中一个为空，则单独对另一个处理；3.最后处理carry可能存在的进位.
 * 备注：要注意最后的carry位，如12+88 = 100，最后要新建一个节点
 *
 * 示例：
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 * @param l1    链表1头节点
 * @param l2    链表2头节点
 * @return      相加的结果的链表头指针
 */

ListNode *P0002_AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2) {
    //链表为空时
    if (l1 == nullptr || l2 == nullptr) {
        if (l1 == nullptr)
            return l2;
        else
            return l1;
    }
    //计算第一个结点的值用于建立头节点
    int sum = l1->val + l2->val;
    int carry = sum / 10;       //进位
    int digit = sum % 10;       //个位数字

    //建立头结点
    ListNode *resultHead = nullptr;
    ListNode *pNode = new ListNode(digit);
    resultHead = pNode;

    //逐个计算
    ListNode *pNode1 = l1->next;
    ListNode *pNode2 = l2->next;
    while (pNode1 && pNode2) {
        //相加计算
        sum = pNode1->val + pNode2->val + carry;
        carry = sum / 10;
        digit = sum % 10;

        //建立新结点
        ListNode *tempNode = new ListNode(digit);
        pNode->next = tempNode;
        pNode = pNode->next;

        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }

    //当链表1不为空，而链表2为空
    while (pNode1) {
        sum = pNode1->val + carry;
        carry = sum / 10;
        digit = sum % 10;

        ListNode *tempNode = new ListNode(digit);
        pNode->next = tempNode;
        pNode = pNode->next;

        pNode1 = pNode1->next;
    }

    //当链表2不为空，而链表1为空
    while (pNode2) {
        sum = pNode2->val + carry;
        carry = sum / 10;
        digit = sum % 10;

        ListNode *tempNode = new ListNode(digit);
        pNode->next = tempNode;
        pNode = pNode->next;

        pNode2 = pNode2->next;
    }

    //当出现一个进位，如1+999 = 1000 ，则需要新建1个结点
    if (carry > 0) {
        ListNode *tempNode = new ListNode(carry);
        pNode->next = tempNode;
    }
    return resultHead;
}

int P0002_AddTwoNumbers::test() {
    ListNode *p1 = new ListNode(9);
    ListNode *p2 = new ListNode(9);
    ListNode *p3 = new ListNode(9);

    ListNode *p4 = new ListNode(1);
    ListNode *p5 = new ListNode(6);
    ListNode *p6 = new ListNode(4);

    p1->next = p2;
    p2->next = p3;

    p4->next = p5;
    p5->next = p6;

    ListNode *num_a = p1;
    ListNode *num_b = p4;

    ListNode *result = addTwoNumbers(num_a, num_b);

    ListNode *pNode = result;
    while (pNode) {
        cout << pNode->val;
        pNode = pNode->next;
    }
    cout << endl;
    return 0;
}
