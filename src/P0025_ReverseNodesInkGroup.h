//
// Created by yongpu on 2019/10/17 11:37.
//

#ifndef LEETCODE_P0025_REVERSENODESINKGROUP_H
#define LEETCODE_P0025_REVERSENODESINKGROUP_H

#include <iostream>
#include "P0000_CommonHead.h"

using namespace std;

class P0025_ReverseNodesInkGroup {
public:
    ListNode* reverseKGroup(ListNode* head, int k);
    ListNode* reverse_list(ListNode* startNode, ListNode* endNode);
    int test();
};


#endif //LEETCODE_P0025_REVERSENODESINKGROUP_H
