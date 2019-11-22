//
// Created by yongpu on 2019/11/22 16:19.
//

#include "P0114_FlattenBinaryTreeToLinkedList.h"

/**
 * 题目：二叉树展开为链表
 * 描述：给定一个二叉树，原地将它展开为链表,右链表形式.
 * 思路：将root作为根节点，然后对左右节点进行递归，将节点都链接到右子树，返回链表尾节点.
 * 备注：注意复习
 */

TreeNode *P0114_FlattenBinaryTreeToLinkedList::flatten_sub(TreeNode *PreNode, TreeNode *child) {
    PreNode->left = nullptr;    // 左节点设空
    PreNode->right = child;     // 将节点连接到父节点的右子树
    PreNode = child;            // PreNode 指向右子树，类似于 node = node->next;

    TreeNode *lChild = PreNode->left;   // 获取左孩子
    TreeNode *rChild = PreNode->right;  // 获取右孩子
    if (lChild) {               // 左孩子不为空，则递归
        PreNode = flatten_sub(PreNode, lChild);
    }
    if (rChild) {               // 右孩子不为空，则递归
        PreNode = flatten_sub(PreNode, rChild);
    }
    return PreNode;             // 返回最后一个节点的指针，即链表尾部
}

void P0114_FlattenBinaryTreeToLinkedList::flatten(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    TreeNode *PreNode = root;       // 头节点

    TreeNode *lChild = root->left;
    TreeNode *rChild = root->right;
    if (lChild) {                   // 左子树不为空，转换链表，返回PreNode为最后一个节点指针
        PreNode = flatten_sub(PreNode, lChild);
    }
    if (rChild) {                   // 右子树不为空，转换链表，返回PreNode为最后一个节点指针
        PreNode = flatten_sub(PreNode, rChild);
    }
}

int P0114_FlattenBinaryTreeToLinkedList::test() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(5);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    TreeNode *t6 = new TreeNode(6);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->right = t6;

    TreeNode *root = t1;
    flatten(root);
    return 0;
}
