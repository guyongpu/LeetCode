//
// Created by yongpu on 2019/11/21 9:44.
//

#ifndef LEETCODE_P0105_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
#define LEETCODE_P0105_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0105_ConstructBinaryTreeFromPreorderAndInorderTraversal {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    int test();
};


#endif //LEETCODE_P0105_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
