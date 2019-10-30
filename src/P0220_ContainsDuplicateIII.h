//
// Created by yongpu on 2019/10/28 18:58.
//

#ifndef LEETCODE_P0220_CONTAINSDUPLICATEIII_H
#define LEETCODE_P0220_CONTAINSDUPLICATEIII_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class P0220_ContainsDuplicateIII {
public:
    bool containsNearbyAlmostDuplicate_1(vector<int>& nums, int k, int t);
    bool containsNearbyAlmostDuplicate_2(vector<int>& nums, int k, int t);
    int test();
};


#endif //LEETCODE_P0220_CONTAINSDUPLICATEIII_H
