//
// Created by yongpu on 2019/11/23 21:42.
//

#ifndef LEETCODE_P0120_TRIANGLE_H
#define LEETCODE_P0120_TRIANGLE_H

#include <iostream>
#include <vector>

using namespace std;

class P0120_Triangle {
public:

    // 动态规划
    int minimumTotal(vector<vector<int>>& triangle);

    // 递归(超时)
    int minimumTotal_2(vector<vector<int>>& triangle);
    int test();
};


#endif //LEETCODE_P0120_TRIANGLE_H
