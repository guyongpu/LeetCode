//
// Created by yongpu on 2019/11/22 10:10.
//

#include "P0109_ConvertSortedListToBinarySearchTree.h"

/**
 * 题目：有序链表转换二叉搜索树
 * 描述：给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 思路：确定链表长度，然后每次取中间的节点，再递归构建左右子树.
 * 备注：常见题，要掌握
 */

TreeNode *sortedListToBST_sub(ListNode *head, int len) {
    if (len == 0) {
        return nullptr;
    }

    ListNode *pNode = head;
    int index = 0;
    while (pNode) {
        if (index == len / 2) {
            break;
        } else {
            index++;
            pNode = pNode->next;
        }
    }

    TreeNode *root = new TreeNode(pNode->val);

    ListNode *Left_ListNode = head;
    int Left_len = index;

    ListNode *Right_ListNode = pNode->next;
    int Right_len = len - index - 1;

    if (Left_len) {
        root->left = sortedListToBST_sub(Left_ListNode, Left_len);
    }
    if (Right_len) {
        root->right = sortedListToBST_sub(Right_ListNode, Right_len);
    }
    return root;

}

TreeNode *P0109_ConvertSortedListToBinarySearchTree::sortedListToBST(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *pNode = head;
    int len = 0;
    while (pNode) {
        len++;
        pNode = pNode->next;
    }
    TreeNode *root = sortedListToBST_sub(head, len);

    return root;
}

int P0109_ConvertSortedListToBinarySearchTree::test() {
    ListNode *p1 = new ListNode(-10);
    ListNode *p2 = new ListNode(-3);
    ListNode *p3 = new ListNode(0);
    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(9);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    TreeNode *root = sortedListToBST(p1);

    return 0;
}
