//
// Created by yongpu on 2019/11/19 20:35.
//

#ifndef LEETCODE_P0099_RECOVERBINARYSEARCHTREE_H
#define LEETCODE_P0099_RECOVERBINARYSEARCHTREE_H

#include <iostream>
#include <stack>
#include "P0000_CommonHead.h"

using namespace std;

class P0099_RecoverBinarySearchTree {
public:
    int cnt = 0;
    bool flag1 = true;
    bool flag2 = true;
    int num1_1 = 0, num1_2 = 0, num1_3 = 0;
    int num2_1 = 0, num2_2 = 0, num2_3 = 0;

    void recoverTree(TreeNode *root);
    void recoverTree_sub(TreeNode *root);

    int test();
};


#endif //LEETCODE_P0099_RECOVERBINARYSEARCHTREE_H
