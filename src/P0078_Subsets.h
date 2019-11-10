//
// Created by yongpu on 2019/11/10 14:43.
//

#ifndef LEETCODE_P0078_SUBSETS_H
#define LEETCODE_P0078_SUBSETS_H

#include <iostream>
#include <vector>

using namespace std;

class P0078_Subsets {
public:
    vector<vector<int>> subsets(vector<int>& nums);

    void dfs(vector<vector<int>> &result, vector<int> path, vector<int> nums, int curr, int len);

    int test();

};


#endif //LEETCODE_P0078_SUBSETS_H
