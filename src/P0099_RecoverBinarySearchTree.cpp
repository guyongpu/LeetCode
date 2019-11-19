//
// Created by yongpu on 2019/11/19 20:35.
//

#include "P0099_RecoverBinarySearchTree.h"


int cccc = 0;

void P0099_RecoverBinarySearchTree::recoverTree_sub(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    if (root->left) {
        recoverTree_sub(root->left);
    }

    /*****************************************/

    if (cnt == 0) {
        num1_1 = root->val;
        num2_1 = root->val;
    } else if (cnt == 1) {
        num1_2 = root->val;
        num2_2 = root->val;
    } else if (cnt == 2) {

        num1_3 = root->val;
        num2_3 = root->val;
    } else {
        if (flag1 == true) {
            num1_1 = num1_2;
            num1_2 = num1_3;
            num1_3 = root->val;
        }
        if (flag2 == true) {
            num2_1 = num2_2;
            num2_2 = num2_3;
            num2_3 = root->val;
        }
    }
    cnt++;
    // 小 - 大 - 小
    if (cnt >= 3 && num1_1 < num1_2 && num1_2 > num1_3) {
        flag1 = false;
    }

    // 大 - 小 - 大
    if (cnt >= 2 && num2_1 > num2_2 && num2_2 < num2_3) {
        flag2 = false;
    }

    cout << root->val << " ";
    /*****************************************/

    if (root->right) {
        recoverTree_sub(root->right);
    }
}

void P0099_RecoverBinarySearchTree::recoverTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    recoverTree_sub(root);
    cout << endl;
    cout << "num1_1 = " << num1_1 << "  num1_2 = " << num1_2 << "  num1_3 = " << num1_3 << endl;
    cout << "num2_1 = " << num2_1 << "  num2_2 = " << num2_2 << "  num2_3 = " << num2_3 << endl;
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
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    TreeNode *root = t1;
    recoverTree(root);

    return 0;
}
