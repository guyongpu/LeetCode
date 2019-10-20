//
// Created by yongpu on 2019/10/16 11:10.
//

#include "P0021_MergeTwoSortedLists.h"

/**
 * 题目：合并两个有序链表
 * 描述：将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的.
 * 思路：每次选择较小的链表头进行匹配.
 * 备注：常见题
 */

ListNode *P0021_MergeTwoSortedLists::mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    ListNode *pNode1 = l1;
    ListNode *pNode2 = l2;
    ListNode *pHead = nullptr;

    //构造头节点
    if (pNode1->val < pNode2->val) {
        pHead = pNode1;
        pNode1 = pNode1->next;
    } else {
        pHead = pNode2;
        pNode2 = pNode2->next;
    }
    ListNode *pNode = pHead;

    //开始合并
    while (pNode1 || pNode2) {                  //pNode1或pNode2不为空
        if (pNode1 && pNode2) {                 //1.pNode1 和 pNode2均还存在节点
            if (pNode1->val < pNode2->val) {
                pNode->next = pNode1;
                pNode = pNode->next;

                pNode1 = pNode1->next;
            } else {
                pNode->next = pNode2;
                pNode = pNode->next;

                pNode2 = pNode2->next;
            }
        } else if (pNode1) {                    //2.pNode1不为空，pNode2为空
            while (pNode1) {
                pNode->next = pNode1;
                pNode = pNode->next;

                pNode1 = pNode1->next;
            }
        } else {                                //3.pNode1为空，pNode2不为空
            while (pNode2) {
                pNode->next = pNode2;
                pNode = pNode->next;

                pNode2 = pNode2->next;
            }
        }
    }

    return pHead;
}

int P0021_MergeTwoSortedLists::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(3);
    ListNode *p3 = new ListNode(5);
    ListNode *p4 = new ListNode(7);
    ListNode *p5 = new ListNode(10);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    ListNode *p6 = new ListNode(2);
    ListNode *p7 = new ListNode(4);
    ListNode *p8 = new ListNode(6);
    ListNode *p9 = new ListNode(8);
    ListNode *p10 = new ListNode(12);

    p6->next = p7;
    p7->next = p8;
    p8->next = p9;
    p9->next = p10;

    ListNode *l1 = p1;
    ListNode *l2 = p6;

    ListNode *head = mergeTwoLists(l1, l2);

    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;

    return 0;
}
