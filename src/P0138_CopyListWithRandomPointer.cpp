//
// Created by yongpu on 2019/12/26 14:45.
//

#include "P0138_CopyListWithRandomPointer.h"

/**
 * 题目：复制带随机指针的链表
 * 描述：给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深拷贝。
 * 思路：此题思路与P133克隆图一样，分为两步，1.建立新节点，建立新旧节点的map映射，并给val赋值；2.遍历节点，利用map建立新节点之间的映射.
 * 备注：掌握思路
 */

P138_Node *P0138_CopyListWithRandomPointer::copyRandomList(P138_Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    map<P138_Node *, P138_Node *> map_list;
    P138_Node *new_head = new P138_Node(0, nullptr, nullptr);

    P138_Node *old_node = head;
    P138_Node *new_node = new_head;

    // 1.建立链表
    while (old_node) {
        // 新建节点
        P138_Node *temp = new P138_Node(old_node->val, nullptr, nullptr);

        // 连接到new链表上
        new_node->next = temp;

        // 构造映射map
        map_list[old_node] = temp;

        // 下一个节点
        new_node = new_node->next;
        old_node = old_node->next;
    }

    // 2.构造映射
    old_node = head;
    new_node = new_head->next;
    while (old_node) {
        P138_Node *temp = old_node->random;
        new_node->random = map_list[temp];

        old_node = old_node->next;
        new_node = new_node->next;
    }

    return new_head->next;
}

int P0138_CopyListWithRandomPointer::test() {
    return 0;
}
