//
// Created by yongpu on 2019/12/28 15:20.
//

#include "P0235_LowestCommonAncestorOfA_BinarySearchTree.h"

/**
 * 题目：二叉搜索树的最近公共祖先
 * 描述：给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先.
 * 思路：当满足 p.val <= node.val <= q.val，则node为所求节点.
 * 备注：掌握递归和非递归方式
 */
TreeNode *
P0235_LowestCommonAncestorOfA_BinarySearchTree::lowestCommonAncestor_1(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (p->val == q->val) {
        return q;
    } else if (p->val > q->val) {
        swap(p, q);
    }

    if (p->val <= root->val && root->val <= q->val) {
        return root;
    } else if (p->val <= root->val && q->val <= root->val) {
        return lowestCommonAncestor_1(root->left, p, q);
    } else {
        return lowestCommonAncestor_1(root->right, p, q);
    }
}


TreeNode *
P0235_LowestCommonAncestorOfA_BinarySearchTree::lowestCommonAncestor_2(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (p->val == q->val) {
        return q;
    } else if (p->val > q->val) {
        swap(p, q);
    }

    TreeNode *node = root;
    while (node) {
        if (p->val <= node->val && node->val <= q->val) {
            return node;
        } else if (p->val <= node->val && q->val <= node->val) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return nullptr;
}

int P0235_LowestCommonAncestorOfA_BinarySearchTree::test() {
    TreeNode *p1 = new TreeNode(6);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(8);
    TreeNode *p4 = new TreeNode(0);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(7);
    TreeNode *p7 = new TreeNode(9);
    TreeNode *p8 = new TreeNode(3);
    TreeNode *p9 = new TreeNode(5);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    p5->left = p8;
    p5->right = p9;

    TreeNode *node = lowestCommonAncestor_2(p1, p4, p9);
    if (node) {
        cout << node->val << endl;
    }
    return 0;
}
