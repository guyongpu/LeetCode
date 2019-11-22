//
// Created by yongpu on 2019/11/22 16:19.
//

#ifndef LEETCODE_P0114_FLATTENBINARYTREETOLINKEDLIST_H
#define LEETCODE_P0114_FLATTENBINARYTREETOLINKEDLIST_H

#include <iostream>
#include "P0000_CommonHead.h"

using namespace std;

class P0114_FlattenBinaryTreeToLinkedList {
public:
    void flatten(TreeNode *root);

    TreeNode *flatten_sub(TreeNode *PreNode, TreeNode *child);

    int test();
};


#endif //LEETCODE_P0114_FLATTENBINARYTREETOLINKEDLIST_H
