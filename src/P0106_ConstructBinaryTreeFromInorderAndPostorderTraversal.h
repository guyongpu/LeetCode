//
// Created by yongpu on 2019/11/21 16:00.
//

#ifndef LEETCODE_P0106_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
#define LEETCODE_P0106_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "P0000_CommonHead.h"

using namespace std;

class P0106_ConstructBinaryTreeFromInorderAndPostorderTraversal {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);

    int test();
};


#endif //LEETCODE_P0106_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H
