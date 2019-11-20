//
// Created by yongpu on 2019/11/19 20:35.
//

#ifndef LEETCODE_P0099_RECOVERBINARYSEARCHTREE_H
#define LEETCODE_P0099_RECOVERBINARYSEARCHTREE_H

#include <iostream>
#include <vector>

#include "P0000_CommonHead.h"

using namespace std;

class P0099_RecoverBinarySearchTree {
public:

    void recoverTree(TreeNode *root);

    void
    recoverTree_sub(TreeNode *root, int &cnt, bool &flag1, int &num,int &targetNum1, int &targetNum2);

    void recoverTree_exchange(TreeNode *root, int targetNum1, int targetNum2);

    int test();
};


#endif //LEETCODE_P0099_RECOVERBINARYSEARCHTREE_H
