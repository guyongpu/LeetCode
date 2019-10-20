//
// Created by yongpu on 2019/10/17 11:37.
//

#include "P0025_ReverseNodesInkGroup.h"

/**
 * 题目：K个一组翻转链表
 * 描述：给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表.
 * 思路：分两步处理，先翻转第一段，确定头，然后再翻转剩余的部分.将每段翻转后的头连接到上一段的尾节点上.
 * 备注：本身不难，但是需要十分地仔细
 */

ListNode *P0025_ReverseNodesInkGroup::reverseKGroup(ListNode *head, int k) {
    if (k <= 1)
        return head;
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode *pNode = head;
    ListNode *startNode = pNode;
    ListNode *endNode = nullptr;
    int step = 0;
    bool flag = false;

    //先处理头
    while (pNode) {
        step++;
        if (step == k) {
            endNode = pNode;
            pNode = pNode->next;
            flag = true;
            break;
        } else {
            pNode = pNode->next;
        }
    }

    if (flag == false) {  //链表不足k个节点
        return head;
    }

    //1.翻转第一段[start,end],pNode为下一段的起始节点
    head = reverse_list(startNode, endNode);

    //2.翻转pNode之后的节点
    while(1){
        ListNode *pNode_head = startNode;   //上一段的尾节点
        startNode = pNode;
        flag = false;
        step = 0;
        while (pNode) {
            step++;
            if (step == k) {
                endNode = pNode;
                pNode = pNode->next;
                flag = true;
                break;
            } else {
                pNode = pNode->next;
            }
        }
        if (flag == false) {  //链表不足k个节点
            pNode_head->next = startNode;
            break;
        }

        ListNode * pNode_temp = reverse_list(startNode, endNode);   //翻转后得到的头pNode_temp
        pNode_head->next = pNode_temp;                              //将pNode_temp连接到上一段的尾节点pNode_head上面
    }

    return head;
}

ListNode *P0025_ReverseNodesInkGroup::reverse_list(ListNode *startNode, ListNode *endNode) {
    ListNode *pNode_front = nullptr;
    ListNode *pNode_cuur = startNode;
    endNode->next = nullptr;
    while(pNode_cuur){
        ListNode *pNode_next = pNode_cuur->next;
        pNode_cuur->next = pNode_front;

        pNode_front = pNode_cuur;
        pNode_cuur = pNode_next;
    }

    return pNode_front;
}

int P0025_ReverseNodesInkGroup::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);
    ListNode *p8 = new ListNode(8);
    ListNode *p9 = new ListNode(9);
    ListNode *p10 = new ListNode(10);

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
    ListNode *newHead = reverseKGroup(head, 3);
    ListNode *pNode = newHead;

    while (pNode) {
        cout << pNode->val << " ";
        pNode = pNode->next;
    }
    cout << endl;

    return 0;
}
