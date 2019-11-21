//
// Created by yongpu on 2019/11/21 17:10.
//

#ifndef LEETCODE_P0108_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
#define LEETCODE_P0108_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H

#include <iostream>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0108_ConvertSortedArrayToBinarySearchTree {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums);
    int test();
};


#endif //LEETCODE_P0108_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H
