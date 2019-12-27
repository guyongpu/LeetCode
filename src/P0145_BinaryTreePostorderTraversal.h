//
// Created by yongpu on 2019/12/27 16:50.
//

#ifndef LEETCODE_P0145_BINARYTREEPOSTORDERTRAVERSAL_H
#define LEETCODE_P0145_BINARYTREEPOSTORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "P0000_CommonHead.h"

using namespace std;

class P0145_BinaryTreePostorderTraversal {
public:
    vector<int> postorderTraversal_1(TreeNode *root);
    vector<int> postorderTraversal_2(TreeNode *root);

    int test();
};


#endif //LEETCODE_P0145_BINARYTREEPOSTORDERTRAVERSAL_H
