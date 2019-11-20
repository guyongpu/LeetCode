//
// Created by yongpu on 2019/11/20 17:01.
//

#ifndef LEETCODE_P0103_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
#define LEETCODE_P0103_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "P0000_CommonHead.h"

using namespace std;

class P0103_BinaryTreeZigzagLevelOrderTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root);

    int test();
};


#endif //LEETCODE_P0103_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H
