//
// Created by yongpu on 2019/10/31 9:47.
//

#ifndef LEETCODE_P0046_PERMUTATIONS_H
#define LEETCODE_P0046_PERMUTATIONS_H

#include <iostream>
#include <vector>

using namespace std;

class P0046_Permutations {
public:
    vector<vector<int>> permute(vector<int> &nums);

    void permute_sub(vector<vector<int>> &result, vector<int> nums, int begin, int len);

    int test();
};


#endif //LEETCODE_P0046_PERMUTATIONS_H
