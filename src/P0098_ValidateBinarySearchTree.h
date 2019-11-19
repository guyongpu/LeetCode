//
// Created by yongpu on 2019/11/18 21:24.
//

#ifndef LEETCODE_P0098_VALIDATEBINARYSEARCHTREE_H
#define LEETCODE_P0098_VALIDATEBINARYSEARCHTREE_H

#include <iostream>
#include <stack>
#include "P0000_CommonHead.h"

using namespace std;

class P0098_ValidateBinarySearchTree {
public:
    bool isValidBST_1(TreeNode *root);
    void isValidBST_sub(bool &result, int &index, int &PrevNum, TreeNode *root);

    bool isValidBST_2(TreeNode *root);

    int test();
};


#endif //LEETCODE_P0098_VALIDATEBINARYSEARCHTREE_H
