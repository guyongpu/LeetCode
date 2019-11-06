//
// Created by yongpu on 2019/11/6 9:10.
//

#ifndef LEETCODE_P0051_N_QUEENS_H
#define LEETCODE_P0051_N_QUEENS_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class P0051_N_Queens {
public:
    vector<vector<string>> solveNQueens_1(int n);
    vector<vector<string>> solveNQueens_2(int n);

    void
    dfs_1_1(vector<vector<string>> &result, unordered_map<int, bool> &rowMap, unordered_map<int, bool> &colMap,
        unordered_map<int, bool> &LineMap1, unordered_map<int, bool> &LineMap2,
        vector<string> temp_ans, int n, int x, int y, int Qnum);

    void
    dfs_1_2(vector<vector<string>> &result, unordered_map<int, bool> &rowMap, unordered_map<int, bool> &colMap,
            unordered_map<int, bool> &LineMap1, unordered_map<int, bool> &LineMap2,
            vector<string> temp_ans, int n, int x, int y, int Qnum);

    void
    dfs_2(vector<vector<string>> &result, unordered_map<int, bool> &rowMap, unordered_map<int, bool> &colMap,
             unordered_map<int, bool> &LineMap1, unordered_map<int, bool> &LineMap2,
             vector<string> temp_ans, int n, int x, int y, int Qnum);

    int test();
};


#endif //LEETCODE_P0051_N_QUEENS_H
