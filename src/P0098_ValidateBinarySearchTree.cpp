//
// Created by yongpu on 2019/11/18 21:24.
//

#include "P0098_ValidateBinarySearchTree.h"

void isValidBST_sub(bool &result, int &index, int &PrevNum, TreeNode *root) {
    if (root == nullptr || result == false) {
        return;
    }
    if (root->left) {
        isValidBST_sub(result, index, PrevNum, root->left);
    }

    if (result == false) {
        return;
    }
    /* 访问数据 */
    if (index == 0) {
        index++;
        PrevNum = root->val;
    } else {
        index++;
        if (PrevNum < root->val) {
            result = true;
        } else {
            result = false;
            return;
        }
        PrevNum = root->val;
    }
    cout << root->val << " ";

    if (root->right) {
        isValidBST_sub(result, index, PrevNum, root->right);
    }
}

bool P0098_ValidateBinarySearchTree::isValidBST(TreeNode *root) {
    bool result = true;

    if (root == nullptr) {
        return result;
    }
    int index = 0;
    int PrevNum = 0;

    isValidBST_sub(result, index, PrevNum, root);

    return result;
}

int P0098_ValidateBinarySearchTree::test() {
    TreeNode *t1 = new TreeNode(10);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(15);
    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(20);

    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    TreeNode *root = t1;
    cout << isValidBST(root) << endl;

    return 0;
}
