//
// Created by yongpu on 2019/11/5 9:27.
//

#ifndef LEETCODE_P0061_ROTATELIST_H
#define LEETCODE_P0061_ROTATELIST_H

#include <iostream>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0061_RotateList {
public:
    ListNode *rotateRight_1(ListNode *head, int k);
    ListNode *rotateRight_2(ListNode *head, int k);
    ListNode *reverseList(ListNode *node_start, ListNode *node_end);

    int test();

};


#endif //LEETCODE_P0061_ROTATELIST_H
