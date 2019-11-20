//
// Created by yongpu on 2019/11/19 20:35.
//

#include "P0099_RecoverBinarySearchTree.h"

/**
 * 题目：恢复二叉搜索树
 * 描述：二叉搜索树中的两个节点被错误地交换，请在不改变其结构的情况下，恢复这棵树。
 * 思路：找个两个数，首次满足 num > root->val,则 targetNum1 = num,最后一次满足 num > root->val，则 targetNum1 = root->val,然后再中序遍历进行交换.
 * 备注：两次中序遍历，第一次寻找，第二次交换
 */

/**
 * 中序遍历，寻找交换的两个点 targetNum1，targetNum2
 * @param root          树根
 * @param cnt           访问计数器
 * @param flag1         targetNum1的标志位，targetNum1只找第一个符合的，小-大-小，即 num > root->val
 * @param num           访问的前一个数据
 * @param targetNum1    目标数据1   首次满足 num > root->val ，则 targetNum1 = num
 * @param targetNum2    目标数据2   最后一次满足 num > root->val，则 targetNum1 = root->val
 */
void
P0099_RecoverBinarySearchTree::recoverTree_sub(TreeNode *root, int &cnt, bool &flag1, int &num, int &targetNum1,
                                               int &targetNum2) {
    if (root == nullptr) {
        return;
    }
    if (root->left) {
        recoverTree_sub(root->left, cnt, flag1, num, targetNum1, targetNum2);
    }

    /*****************************************/
    if (cnt == 0) {
        num = root->val;
    } else {
        // num
        if (num > root->val) {
            if (flag1) {
                targetNum1 = num;
                flag1 = false;
            }
            targetNum2 = root->val;
        }
    }
    cnt = 1;
    num = root->val;

    cout << root->val << " ";
    /*****************************************/

    if (root->right) {
        recoverTree_sub(root->right, cnt, flag1, num, targetNum1, targetNum2);
    }
}

/**
 * 中序遍历，将 targetNum1 与 targetNum2 交换值
 * @param root
 * @param targetNum1
 * @param targetNum2
 */
void P0099_RecoverBinarySearchTree::recoverTree_exchange(TreeNode *root, int targetNum1, int targetNum2) {
    if (root == nullptr) {
        return;
    }
    if (root->left) {
        recoverTree_exchange(root->left, targetNum1, targetNum2);
    }

    /* 中序数据处理 */
    if (root->val == targetNum1) {
        root->val = targetNum2;
    } else if (root->val == targetNum2) {
        root->val = targetNum1;
    }
    cout << root->val << " ";

    if (root->right) {
        recoverTree_exchange(root->right, targetNum1, targetNum2);
    }

}

void P0099_RecoverBinarySearchTree::recoverTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    int cnt = 0;
    int num = 0;
    bool flag1 = true;

    int targetNum1 = 0;
    int targetNum2 = 0;

    // 先找到交换的节点值 targetNum1 与 targetNum2
    recoverTree_sub(root, cnt, flag1, num, targetNum1, targetNum2);
    cout << endl;
    cout << "targetNum1 = " << targetNum1 << "  targetNum2 = " << targetNum2 << endl;

    // 将 targetNum1 与 targetNum2 交换
    recoverTree_exchange(root, targetNum1, targetNum2);
    cout << endl;

}

int P0099_RecoverBinarySearchTree::test() {

    TreeNode *t1 = new TreeNode(19);
    TreeNode *t2 = new TreeNode(7);
    TreeNode *t3 = new TreeNode(16);    //25
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(25);    //16
    TreeNode *t6 = new TreeNode(21);
    TreeNode *t7 = new TreeNode(26);

    t1->left = t2;
/*
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;
*/
    TreeNode *root = t1;
    recoverTree(root);

    return 0;
}

