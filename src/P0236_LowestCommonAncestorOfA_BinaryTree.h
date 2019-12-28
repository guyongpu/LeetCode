//
// Created by yongpu on 2019/12/28 15:55.
//

#ifndef LEETCODE_P0236_LOWESTCOMMONANCESTOROFA_BINARYTREE_H
#define LEETCODE_P0236_LOWESTCOMMONANCESTOROFA_BINARYTREE_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include "P0000_CommonHead.h"

using namespace std;

class P0236_LowestCommonAncestorOfA_BinaryTree {
public:
    TreeNode *lowestCommonAncestor_1(TreeNode *root, TreeNode *p, TreeNode *q);

    TreeNode *lowestCommonAncestor_2(TreeNode *root, TreeNode *p, TreeNode *q);

    int test();
};


#endif //LEETCODE_P0236_LOWESTCOMMONANCESTOROFA_BINARYTREE_H
