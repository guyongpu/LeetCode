//
// Created by yongpu on 2019/11/19 15:15.
//

#include "P0100_SameTree.h"

/**
 *  题目：相同的树
 *  描述：给定两个二叉树，编写一个函数来检验它们是否相同。如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的.
 *  思路：方法1.直接递归判断，采用先序遍历思想，不断比较节点值；方法2.使用迭代方法，采用层序遍历思想。
 *  备注：先序遍历+层序遍历
 */

bool P0100_SameTree::isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr || q == nullptr) {         // 如果p或q为空
        if (p == nullptr && q == nullptr) {     // 都为空，则返回true
            return true;
        } else {                                // 只有一个为空，则返回false
            return false;
        }
    } else {                                    // 都不为空
        if (p->val == q->val) {                 // 比较节点值
            bool result1 = isSameTree(p->left, q->left);
            bool result2 = isSameTree(p->right, q->right);
            return  result1 && result2;
        } else {                                // 不相等，则返回false
            return false;
        }
    }
}

int P0100_SameTree::test() {
    TreeNode *t11 = new TreeNode(1);
    TreeNode *t12 = new TreeNode(2);
    TreeNode *t13 = new TreeNode(3);

    t11->left = t12;
    t11->right = t13;

    TreeNode *t21 = new TreeNode(1);
    TreeNode *t22 = new TreeNode(2);
    TreeNode *t23 = new TreeNode(34);

    t21->left = t22;
    t21->right = t23;

    TreeNode *root1 = t11;
    TreeNode *root2 = t21;

    cout << isSameTree(root1, root2) << endl;

    return 0;
}
