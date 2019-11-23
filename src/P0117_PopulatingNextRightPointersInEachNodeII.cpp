//
// Created by yongpu on 2019/11/23 16:56.
//

#include "P0117_PopulatingNextRightPointersInEachNodeII.h"

/**
 * 题目：填充每个节点的下一个右侧节点指针II
 * 描述：填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL.
 * 思路：将每层看做一个链表，再进行下一层时，利用上一层的链表进行遍历拼接.
 * 备注：掌握此方法
 */


Node *P0117_PopulatingNextRightPointersInEachNodeII::connect(Node *root) {
    Node *cur = root;
    while (cur != nullptr) {
        Node *dummy = new Node();
        Node *tail = dummy;
        //遍历 cur 的当前层
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                tail->next = cur->left;
                tail = tail->next;
            }
            if (cur->right != nullptr) {
                tail->next = cur->right;
                tail = tail->next;
            }
            cur = cur->next;
        }
        //更新 cur 到下一层
        cur = dummy->next;

        // 将dummy 置空
        dummy->left = nullptr;
        dummy->right = nullptr;
        dummy->next = nullptr;
    }
    return root;
}

int P0117_PopulatingNextRightPointersInEachNodeII::test() {
    Node *t1 = new Node(1, nullptr, nullptr, nullptr);
    Node *t2 = new Node(2, nullptr, nullptr, nullptr);
    Node *t3 = new Node(3, nullptr, nullptr, nullptr);
    Node *t4 = new Node(4, nullptr, nullptr, nullptr);
    Node *t5 = new Node(5, nullptr, nullptr, nullptr);
    Node *t6 = new Node(6, nullptr, nullptr, nullptr);
    Node *t7 = new Node(7, nullptr, nullptr, nullptr);
    Node *t8 = new Node(8, nullptr, nullptr, nullptr);

    t1->right = t2;
    t2->right = t3;
    t3->right = t4;

    t1->left = t5;

    t5->left = t6;
    t5->right = t7;

    t6->left = t8;

    Node *root = connect(t1);
    return 0;
}
