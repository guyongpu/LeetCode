//
// Created by yongpu on 2019/10/16 15:32.
//

#ifndef LEETCODE_P0173_BINARYSEARCHTREEITERATOR_H
#define LEETCODE_P0173_BINARYSEARCHTREEITERATOR_H

#include <iostream>
#include <stack>
#include "P0000_CommonHead.h"

using namespace std;

class P0173_BinarySearchTreeIterator {
public:
    TreeNode *curr;
    stack<TreeNode *> s;

    P0173_BinarySearchTreeIterator(TreeNode *root = nullptr);

    int next();

    bool hasNext();

    int test();
};


#endif //LEETCODE_P0173_BINARYSEARCHTREEITERATOR_H
