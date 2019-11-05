//
// Created by yongpu on 2019/11/5 17:24.
//

#ifndef LEETCODE_P0980_UNIQUEPATHSIII_H
#define LEETCODE_P0980_UNIQUEPATHSIII_H

#include <iostream>
#include <vector>

using namespace std;

class P0980_UniquePathsIII {
public:
    int uniquePathsIII(vector<vector<int>> &grid);

    void dfs(vector<vector<int>> grid, int n, int m, int x, int y, vector<vector<bool>> &visitFlag, int cntOf0, int stepCnt,
             int &result);
    void dfs_2(vector<vector<int>> grid, int n, int m, int x, int y, vector<vector<bool>> &visitFlag, int cntOf0, int stepCnt,
             int &result);

    int test();
};


#endif //LEETCODE_P0980_UNIQUEPATHSIII_H
