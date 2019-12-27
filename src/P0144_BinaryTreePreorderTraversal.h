//
// Created by yongpu on 2019/12/27 15:23.
//

#ifndef LEETCODE_P0144_BINARYTREEPREORDERTRAVERSAL_H
#define LEETCODE_P0144_BINARYTREEPREORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include <stack>
#include "P0000_CommonHead.h"

using namespace std;

class P0144_BinaryTreePreorderTraversal {
public:
    vector<int> preorderTraversal_1(TreeNode* root);
    vector<int> preorderTraversal_2(TreeNode* root);
    int test();

};


#endif //LEETCODE_P0144_BINARYTREEPREORDERTRAVERSAL_H
