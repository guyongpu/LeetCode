//
// Created by yongpu on 2019/11/17 14:38.
//

#include "P0095_UniqueBinarySearchTreesII.h"

/**
 * 题目：不同的二叉搜索树II
 * 描述：给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树.
 * 思路：不断以start-end为起点终点构建树，当start>end时，result中放入null，递归构建树.
 * 备注：注意复习.
 */

vector<TreeNode *> generateTrees_sub(int start, int end) {
    vector<TreeNode *> result;
    if (start > end) {
        result.push_back(nullptr);  //代表start和end之间没有值，要为null
    }
    for (int i = start; i <= end; i++) {
        vector<TreeNode *> left = generateTrees_sub(start, i - 1);
        vector<TreeNode *> right = generateTrees_sub(i + 1, end);

        for (auto iter_l : left) {
            for (auto iter_r : right) {
                TreeNode *root = new TreeNode(i);
                root->left = iter_l;
                root->right = iter_r;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode *> P0095_UniqueBinarySearchTreesII::generateTrees(int n) {
    vector<TreeNode *> result;
    if (n == 0) {
        return result;
    }
    result = generateTrees_sub(1, n);
    return result;
}

int P0095_UniqueBinarySearchTreesII::test() {
    vector<TreeNode *> result = generateTrees(3);
    return 0;
}

