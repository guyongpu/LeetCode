
//
// Created by yongpu on 2019/10/24 11:48.
//

#ifndef LEETCODE_P0200_NUMBEROFISLANDS_H
#define LEETCODE_P0200_NUMBEROFISLANDS_H

#include <iostream>
#include <vector>

using namespace std;

class P0200_NumberOfIslands {
public:
    int numIslands(vector<vector<char>> &grid);

    void around(vector<vector<char>> &grid, vector<vector<int>> &graphFlag, int row,int col, int i, int j,int val);

    int test();

};


#endif //LEETCODE_P0200_NUMBEROFISLANDS_H
