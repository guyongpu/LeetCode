//
// Created by yongpu on 2019/11/7 9:29.
//

#include "P0064_MinimumPathSum.h"

/**
 * 题目：最小路径和
 * 描述：给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小，每次只能向下或者向右移动一步.
 * 思路：和62,63的思路类似，采用动态规划，dp[i][j]= min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];即为到(i,j)的最小路径和.
 * 备注：掌握动态规划.
 */

int P0064_MinimumPathSum::minPathSum(vector<vector<int>> &grid) {
    if (grid.size() == 0) {
        return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int> > dp(rows, vector<int>(cols, 0));

    dp[0][0] = grid[0][0];
    //初始化dp[0][j] = dp[0][j-1]+gird[0][j]
    for (int j = 1; j < cols; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    //初始化dp[i][0] = dp[i-1][0]+gird[i][0]
    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }

    int result = dp[rows - 1][cols - 1];
    return result;
}

int P0064_MinimumPathSum::test() {
    vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1},
    };
    cout << minPathSum(grid) << endl;
    return 0;
}
