//
// Created by yongpu on 2019/12/27 19:25.
//

#ifndef LEETCODE_P0215_KTHLARGESTELEMENTINANARRAY_H
#define LEETCODE_P0215_KTHLARGESTELEMENTINANARRAY_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class P0215_KthLargestElementInAnArray {
public:
    int findKthLargest_1(vector<int> &nums, int k);
    int findKthLargest_2(vector<int> &nums, int k);

    int test();
};


#endif //LEETCODE_P0215_KTHLARGESTELEMENTINANARRAY_H
