//
// Created by yongpu on 2019/11/5 16:36.
//

#ifndef LEETCODE_P0063_UNIQUEPATHSII_H
#define LEETCODE_P0063_UNIQUEPATHSII_H

#include <iostream>
#include <vector>

using namespace std;

class P0063_UniquePathsII {
public:
    int uniquePathsWithObstacles_1(vector<vector<int>> &obstacleGrid);

    int uniquePathsWithObstacles_2(vector<vector<int>> &obstacleGrid);

    void dfs(vector<vector<int>> &obstacleGrid, int n, int m, int x, int y, int &result);

    int test();
};


#endif //LEETCODE_P0063_UNIQUEPATHSII_H
