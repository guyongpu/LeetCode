//
// Created by yongpu on 2019/12/27 20:29.
//

#ifndef LEETCODE_P0230_KTHSMALLESTELEMENTINA_BST_H
#define LEETCODE_P0230_KTHSMALLESTELEMENTINA_BST_H

#include <iostream>
#include <vector>
#include <stack>
#include "P0000_CommonHead.h"

using namespace std;

class P0230_KthSmallestElementInA_BST {
public:
    int kthSmallest_1(TreeNode *root, int k);
    int kthSmallest_2(TreeNode *root, int k);

    int test();
};


#endif //LEETCODE_P0230_KTHSMALLESTELEMENTINA_BST_H
