//
// Created by yongpu on 2019/11/5 15:53.
//

#ifndef LEETCODE_P0062_UNIQUEPATHS_H
#define LEETCODE_P0062_UNIQUEPATHS_H

#include <iostream>
#include <vector>

using namespace std;

class P0062_UniquePaths {
public:
    int uniquePaths_1(int m, int n);    // 动态规划

    int uniquePaths_2(int m, int n);    // 递归法

    void dfs(int m, int n, int x, int y, int &result);

    int test();
};


#endif //LEETCODE_P0062_UNIQUEPATHS_H
