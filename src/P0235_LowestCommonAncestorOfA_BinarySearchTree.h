//
// Created by yongpu on 2019/12/28 15:20.
//

#ifndef LEETCODE_P0235_LOWESTCOMMONANCESTOROFA_BINARYSEARCHTREE_H
#define LEETCODE_P0235_LOWESTCOMMONANCESTOROFA_BINARYSEARCHTREE_H

#include <iostream>
#include "P0000_CommonHead.h"

using namespace std;

class P0235_LowestCommonAncestorOfA_BinarySearchTree {
public:
    TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q);
    TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q);
    int test();

};


#endif //LEETCODE_P0235_LOWESTCOMMONANCESTOROFA_BINARYSEARCHTREE_H
