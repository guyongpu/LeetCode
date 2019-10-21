//
// Created by yongpu on 2019/10/21 17:26.
//

#include "P0023_MergeKSortedLists.h"

/**
 * 题目：合并K个排序链表
 * 描述：合并 k 个排序链表，返回合并后的排序链表.
 * 思路：每次找最小节点，然后连接到新链表上.1.判空;2.最小节点;3.指针下移;4.接到新链表.时间O(kn)/空间O(1)
 * 备注：也可以全部放到一个vector中，然后sort排序，但时间复杂度较高
 */

ListNode *P0023_MergeKSortedLists::mergeKLists(vector<ListNode *> &lists) {
    ListNode *newHead = new ListNode(0);
    ListNode *newpNode = newHead;

    int len = lists.size();
    vector<ListNode *> headvec;
    for (int i = 0; i < len; i++) {
        headvec.push_back(lists[i]);
    }

    while (1) {
        //1.判断是否全部为空，为空则结束
        bool Empty = true;
        for (int i = 0; i < len; i++) {
            if (headvec[i] != nullptr) {
                Empty = false;
                break;
            }
        }
        if (Empty == true) {  //所有节点全部都为空
            break;
        }

        //2.寻找本轮的最小节点
        ListNode *minNode = new ListNode(INT_MAX);
        int minIndex = 0;                       //最小节点所在的序号
        for (int i = 0; i < len; i++) {         //寻找最小的节点
            if (headvec[i] != nullptr && headvec[i]->val <= minNode->val) {
                minNode = headvec[i];
                minIndex = i;
            }
        }

        //3.指针下移
        headvec[minIndex] = headvec[minIndex]->next;

        //4.接到新链表的下一个节点
        newpNode->next = minNode;
        newpNode = newpNode->next;
    }

    return newHead->next;
}

int P0023_MergeKSortedLists::test() {
    ListNode *pL11 = new ListNode(3);
    ListNode *pL12 = new ListNode(12);
    ListNode *pL13 = new ListNode(17);
    ListNode *pL14 = new ListNode(25);
    pL11->next = pL12;
    pL12->next = pL13;
    pL13->next = pL14;

    ListNode *pL21 = new ListNode(15);
    ListNode *pL22 = new ListNode(32);
    ListNode *pL23 = new ListNode(67);
    ListNode *pL24 = new ListNode(122);
    pL21->next = pL22;
    pL22->next = pL23;
    pL23->next = pL24;

    ListNode *pL31 = new ListNode(11);
    ListNode *pL32 = new ListNode(15);
    ListNode *pL33 = new ListNode(52);
    ListNode *pL34 = new ListNode(72);
    pL31->next = pL32;
    pL32->next = pL33;
    pL33->next = pL34;

    ListNode *pL41 = new ListNode(8);
    ListNode *pL42 = new ListNode(10);
    ListNode *pL43 = new ListNode(32);
    ListNode *pL44 = new ListNode(45);
    pL41->next = pL42;
    pL42->next = pL43;
    pL43->next = pL44;

    ListNode *head1 = pL11;
    ListNode *head2 = pL21;
    ListNode *head3 = pL31;
    ListNode *head4 = pL41;

    vector<ListNode *> lists = {head1, head2, head3, head4};

    ListNode *head = mergeKLists(lists);
    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;

    return 0;
}
