//
// Created by yongpu on 2019/10/16 15:32.
//

#include "P0173_BinarySearchTreeIterator.h"

/**
 * 题目：二叉搜索树迭代器
 * 描述：实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器.
 * 思路：使用栈实现二叉树的中序遍历
 * 备注：重点题，要复习
 */

P0173_BinarySearchTreeIterator::P0173_BinarySearchTreeIterator(TreeNode *root) {
    curr = root;
    while (s.size() != 0) {
        s.pop();
    }
}

int P0173_BinarySearchTreeIterator::next() {
    if (hasNext() == true) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
    } else {
        return -1;
    }

    int res = curr->val;
    curr = curr->right;
    return res;
}


bool P0173_BinarySearchTreeIterator::hasNext() {
    if (s.empty() != true || curr != nullptr) {
        return true;
    } else {
        return false;
    }
}

int P0173_BinarySearchTreeIterator::test() {
    TreeNode *t1 = new TreeNode(7);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(15);
    TreeNode *t4 = new TreeNode(9);
    TreeNode *t5 = new TreeNode(20);

    t1->left = t2;
    t1->right = t3;
    t3->left = t4;
    t3->right = t5;

    TreeNode *root = t1;
    curr = root;

    cout << next() << endl;
    cout << next() << endl;
    cout << hasNext() << endl;
    cout << next() << endl;
    cout << hasNext() << endl;
    cout << next() << endl;
    cout << hasNext() << endl;
    cout << next() << endl;
    cout << hasNext() << endl;

    return 0;
}
