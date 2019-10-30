//
// Created by yongpu on 2019/10/26 9:43.
//

#ifndef LEETCODE_P0040_COMBINATIONSUMII_H
#define LEETCODE_P0040_COMBINATIONSUMII_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class P0040_CombinationSumII {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target);

    void DFS_combinationSum2(vector<vector<int>> &result, map<vector<int>,int> &resultMap,vector<int> &candidates, vector<int> record, int target,
                             int start);

    int test();
};


#endif //LEETCODE_P0040_COMBINATIONSUMII_H
