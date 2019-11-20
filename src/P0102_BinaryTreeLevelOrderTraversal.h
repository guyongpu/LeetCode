//
// Created by yongpu on 2019/11/20 16:32.
//

#ifndef LEETCODE_P0102_BINARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE_P0102_BINARYTREELEVELORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0102_BinaryTreeLevelOrderTraversal {
public:
    vector<vector<int>> levelOrder(TreeNode *root);

    int test();
};


#endif //LEETCODE_P0102_BINARYTREELEVELORDERTRAVERSAL_H
