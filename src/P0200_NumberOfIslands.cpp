//
// Created by yongpu on 2019/10/24 11:48.
//

#include "P0200_NumberOfIslands.h"

/**
 * 题目：岛屿数量
 * 描述：给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量.
 * 思路：使用一个graphFlag标记数组，将陆地进行标记，并递归标记其相邻的所有岛屿.
 * 备注：深度优先搜索+递归标记
 */

int P0200_NumberOfIslands::numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0)
        return 0;
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> graphFlag;
    for (int i = 0; i < row; i++) {
        vector<int> one_row(col, 0);
        graphFlag.push_back(one_row);
    }

    int result = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1') {
                if ((i == 0 || graphFlag[i - 1][j] == 0)                //上面未标记
                    && (i == row - 1 || graphFlag[i + 1][j] == 0)       //下面未标记
                    && (j == 0 || graphFlag[i][j - 1] == 0)             //左边未标记
                    && (j == col - 1 || graphFlag[i][j + 1] == 0)) {    //右边未标记

                    result++;                                           //岛屿数+1
                    graphFlag[i][j] = result;                           //graphFlag[i][j]为第result号岛屿
                } else {                                                //已被标记过，不再处理
                    continue;
                }
                //标记与grid[i][j]相连的岛屿
                int val = graphFlag[i][j];
                around(grid, graphFlag, row, col, i, j, val);
            }
        }
    }
    return result;
}

// 标记grid[i][j]周围元素
void
P0200_NumberOfIslands::around(vector<vector<char>> &grid, vector<vector<int>> &graphFlag, int row, int col, int i,
                              int j,
                              int val) {
    graphFlag[i][j] = val;
    if (i >= 1 && grid[i - 1][j] == '1' && graphFlag[i - 1][j] == 0) {       //上面有元素未被标记
        around(grid, graphFlag, row, col, i - 1, j, val);
    }
    if (i < row - 1 && grid[i + 1][j] == '1' && graphFlag[i + 1][j] == 0) {  //下面有元素未被标记
        around(grid, graphFlag, row, col, i + 1, j, val);
    }
    if (j >= 1 && grid[i][j - 1] == '1' && graphFlag[i][j - 1] == 0) {       //左边有元素未被标记
        around(grid, graphFlag, row, col, i, j - 1, val);
    }
    if (j < col - 1 && grid[i][j + 1] == '1' && graphFlag[i][j + 1] == 0) {  //右边有元素未被标记
        around(grid, graphFlag, row, col, i, j + 1, val);
    }
}


int P0200_NumberOfIslands::test() {
    vector<vector<char>> grid1 = {
            {'1', '1', '0', '1', '0'},
            {'0', '1', '1', '1', '0'},
            {'0', '0', '0', '0', '1'},
            {'0', '1', '0', '1', '1'}
    };
    vector<vector<char>> grid2 = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'0', '0', '1', '1', '1'}
    };
    cout << numIslands(grid2) << endl;
    return 0;
}
