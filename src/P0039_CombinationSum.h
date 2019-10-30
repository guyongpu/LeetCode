//
// Created by yongpu on 2019/10/26 9:12.
//

#ifndef LEETCODE_P0039_COMBINATIONSUM_H
#define LEETCODE_P0039_COMBINATIONSUM_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class P0039_CombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target);

    void
    DFS_combinationSum(vector<vector<int>> &result, vector<int> &candidates, vector<int> record, int target, int start);

    int test();

};


#endif //LEETCODE_P0039_COMBINATIONSUM_H
