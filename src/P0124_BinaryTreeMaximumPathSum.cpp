//
// Created by yongpu on 2019/11/24 16:11.
//

#include "P0124_BinaryTreeMaximumPathSum.h"

/**
 * 题目：二叉树中的最大路径和
 * 描述：给定一个非空二叉树，返回其最大路径和,不一定经过根节点.
 * 思路：left和right分别为左右子树的最大贡献值，result保存结果，然后分情况计算
 * 备注：重点题目，要掌握
 */

int maxPathSum_sub(TreeNode *root, int &val) {
    if (root == nullptr) {
        return 0;
    }
    int left = maxPathSum_sub(root->left, val);
    int right = maxPathSum_sub(root->right, val);

    int lmr = root->val + max(0, left) + max(0, right);   // 左-根-右
    int ret = root->val + max(0, max(left, right));       // 根 / 根+左 / 根+右，可以作为节点贡献值，返回

    // max(lmr, ret)：max(max(根，根+左，根+右，根+左+右)，max(根，根+左，根+右))
    val = max(val, max(lmr, ret));
    return ret;
}

int P0124_BinaryTreeMaximumPathSum::maxPathSum(TreeNode *root) {

    int result = INT_MIN;
    maxPathSum_sub(root, result);
    return result;
}

int P0124_BinaryTreeMaximumPathSum::test() {
    TreeNode *t1 = new TreeNode(-10);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);

    t1->left = t2;
    t1->right = t3;

    t3->left = t4;
    t3->right = t5;

    TreeNode *root = t1;
    cout << maxPathSum(root) << endl;
    return 0;
}
