//
// Created by yongpu on 2019/10/31 10:22.
//

#ifndef LEETCODE_P0047_PERMUTATIONSII_H
#define LEETCODE_P0047_PERMUTATIONSII_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class P0047_PermutationsII {
public:
    // 方法1
    vector<vector<int>> permuteUnique_1(vector<int> &nums);

    void permuteUnique_1_sub(vector<vector<int>> &result, vector<int> nums, int begin, int len);

    // 方法2
    vector<vector<int>> permuteUnique_2(vector<int> &nums);

    void permuteUnique_2_sub(vector<vector<int>> &result, vector<int> nums, int begin, int len);

    bool isRepeat(vector<int> nums, int begin, int index);

    int test();
};


#endif //LEETCODE_P0047_PERMUTATIONSII_H
