//
// Created by yongpu on 2019/11/6 11:41.
//

#ifndef LEETCODE_P0052_N_QUEENSII_H
#define LEETCODE_P0052_N_QUEENSII_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class P0052_N_QueensII {
public:
    int totalNQueens(int n);

    void
    dfs(int &result, unordered_map<int, bool> &rowMap, unordered_map<int, bool> &colMap,
        unordered_map<int, bool> &LineMap1, unordered_map<int, bool> &LineMap2,
        int n, int x, int y, int Qnum);

    int test();
};


#endif //LEETCODE_P0052_N_QUEENSII_H
