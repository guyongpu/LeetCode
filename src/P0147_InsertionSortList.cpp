//
// Created by yongpu on 2019/9/30.
//

#include "P0147_InsertionSortList.h"

/**
 * 题目：对链表进行插入排序
 * 描述：按照插入排序的思想，对链表进行插入排序.
 * 思路：在进行插入排序的时候，对当前待处理节点要保留 NodeFront、NodeCurrent、NodeNext三个节点，对于比较节点要保留 pNode0 和 pNode。
 * 每次对 NodeFront、NodeCurrent、NodeNext 进行更新，另外对于 NodeFront 的处理要分为发生插入或者不发生插入两种情况考虑.
 */

ListNode *P0147_InsertionSortList::insertionSortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *pNode0 = nullptr;     //pNode 的上一个节点
    ListNode *pNode = head;
    ListNode *NodeFront = head;
    ListNode *NodeCurrent = head->next;   //当前节点
    ListNode *NodeNext = NodeCurrent->next;
    bool swap_falg = false;
    while (NodeCurrent) {
        pNode = head;               //从头节点开始遍历
        swap_falg = false;          //是否发生插入，如果发生插入，则NodeFront不变；如果没有，则NodeFront = NodeCurrent
        while (pNode != NodeCurrent) {
            if (NodeCurrent->val < pNode->val) {
                swap_falg = true;                   //发生插入，swap_falg设置为true
                if (pNode == head) {                //在头节点插入
                    //1.对后部分进行连接
                    NodeNext = NodeCurrent->next;   //下一次要处理的节点
                    NodeFront->next = NodeNext;

                    //2.进行插入操作，将NodeCurrent作为头节点
                    NodeCurrent->next = head;
                    head = NodeCurrent;
                } else {                            //在中间某一节点插入
                    //1.对后部分进行连接
                    NodeNext = NodeCurrent->next;   //下一次要处理的节点
                    NodeFront->next = NodeNext;

                    //2.进行插入操作
                    pNode0->next = NodeCurrent;
                    NodeCurrent->next = pNode;
                }
                break;
            }
            pNode0 = pNode;
            pNode = pNode->next;
        }
        if (swap_falg == false) {           //未发生插入
            NodeFront = NodeCurrent;        //当前节点 NodeCurrent 赋值给 NodeFront
            NodeCurrent = NodeNext;         //NodeNext 赋值给 NodeCurrent
            if (NodeCurrent)                //如果 NodeCurrent 为空，则停止循环
                NodeNext = NodeNext->next;  //NodeNext 指向下一个节点
        } else {
            NodeFront = NodeFront;          //当前节点 NodeFront 不改变
            NodeCurrent = NodeNext;         //NodeNext 赋值给 NodeCurrent
            if (NodeCurrent)                //如果 NodeCurrent 为空，则停止循环
                NodeNext = NodeNext->next;  //NodeNext 指向下一个节点
        }
    }

    return head;
}

int P0147_InsertionSortList::test() {
    ListNode *p1 = new ListNode(7);
    ListNode *p2 = new ListNode(6);
    ListNode *p3 = new ListNode(5);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(3);
    ListNode *p6 = new ListNode(2);
    ListNode *p7 = new ListNode(1);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;


    ListNode *head = p6;
    head = insertionSortList(head);
    ListNode *pNode = head;
    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;
    return 0;
}
