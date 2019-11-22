//
// Created by yongpu on 2019/11/22 13:44.
//

#ifndef LEETCODE_P0111_MINIMUMDEPTHOFBINARYTREE_H
#define LEETCODE_P0111_MINIMUMDEPTHOFBINARYTREE_H

#include <iostream>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0111_MinimumDepthOfBinaryTree {
public:
    int minDepth(TreeNode *root);

    int minDepth_2(TreeNode *root);

    int test();
};


#endif //LEETCODE_P0111_MINIMUMDEPTHOFBINARYTREE_H
