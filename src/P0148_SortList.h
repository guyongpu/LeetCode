//
// Created by yongpu on 2019/10/8.
//

#ifndef LEETCODE_P0148_SORTLIST_H
#define LEETCODE_P0148_SORTLIST_H

#include <iostream>
#include "P0000_CommonHead.h"

using namespace std;

class P0148_SortList {
public:
    ListNode *sortList(ListNode *head);

    void QuickSortList(ListNode *pFirst, ListNode *pLast);

    ListNode *Partition(ListNode *pFirst, ListNode *pLast);

    void swap(ListNode *pNode1, ListNode *pNode2);

    ListNode *mergesort(ListNode *node);

    ListNode *merge(ListNode *l1, ListNode *l2);

    int test();
};


#endif //LEETCODE_P0148_SORTLIST_H
