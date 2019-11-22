//
// Created by yongpu on 2019/11/22 11:05.
//

#ifndef LEETCODE_P0110_BALANCEDBINARYTREE_H
#define LEETCODE_P0110_BALANCEDBINARYTREE_H

#include <iostream>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0110_BalancedBinaryTree {
public:
    bool isBalanced_1(TreeNode* root);
    bool isBalanced_sub(TreeNode *pRoot, int &depth);

    bool isBalanced_2(TreeNode* root);
    int TreeDepth(TreeNode *root);
    int test();
};


#endif //LEETCODE_P0110_BALANCEDBINARYTREE_H
