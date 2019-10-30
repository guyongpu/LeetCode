//
// Created by yongpu on 2019/10/28 18:56.
//

#ifndef LEETCODE_P0217_CONTAINSDUPLICATE_H
#define LEETCODE_P0217_CONTAINSDUPLICATE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class P0217_ContainsDuplicate {
public:
    bool containsDuplicate_1(vector<int>& nums);
    bool containsDuplicate_2(vector<int>& nums);
    bool containsDuplicate_3(vector<int>& nums);
    int test();

};


#endif //LEETCODE_P0217_CONTAINSDUPLICATE_H
