//
// Created by yongpu on 2019/11/21 17:10.
//

#include "P0108_ConvertSortedArrayToBinarySearchTree.h"

/**
 * 题目：将有序数组转换为二叉搜索树
 * 描述：将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树.
 * 思路：每次找nums中间的节点作为当前节点值，然后递归建立搜索树.
 * 备注：注意复习
 */

TreeNode *P0108_ConvertSortedArrayToBinarySearchTree::sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0) {
        return nullptr;
    }
    int pos = nums.size() / 2;
    TreeNode *Node = new TreeNode(nums[pos]);

    vector<int> left_num;
    vector<int> right_num;

    left_num.assign(nums.begin(), nums.begin() + pos);
    right_num.assign(nums.begin() + pos + 1, nums.end());

    Node->left = sortedArrayToBST(left_num);
    Node->right = sortedArrayToBST(right_num);

    return Node;
}

int P0108_ConvertSortedArrayToBinarySearchTree::test() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST(nums);
    return 0;
}
