//
// Created by yongpu on 2019/10/21 17:26.
//

#ifndef LEETCODE_P0023_MERGEKSORTEDLISTS_H
#define LEETCODE_P0023_MERGEKSORTEDLISTS_H

#include <iostream>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0023_MergeKSortedLists {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists);
    int test();
};


#endif //LEETCODE_P0023_MERGEKSORTEDLISTS_H
