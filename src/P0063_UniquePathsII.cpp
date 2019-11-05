//
// Created by yongpu on 2019/11/5 16:36.
//

#include "P0063_UniquePathsII.h"

/**
 * 题目：不同路径II
 * 描述：一个机器人位于一个 m x n 网格的左上角，走到右下角，有多少种不同的路径，图中1表示障碍物.
 * 思路：方法1；dp[i][j] = dp[i - 1][j] + dp[i][j - 1];方法2.采用递归回溯，但是会超时.
 * 备注：初始化时dp[0][j]和dp[i][0]要注意，另外起点/终点为1，返回0
 */

// 方法1.动态规划
int P0063_UniquePathsII::uniquePathsWithObstacles_1(vector<vector<int>> &obstacleGrid) {
    int result = 0;
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {     // 注意点1，起点或终点是1，则返回0
        return 0;
    }
    vector<vector<long long int>> dp(n, vector<long long int>(m, 0));   //不然会溢出

    //dp[i][0]与dp[0][j]初始化
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = 1;
        } else {                    //注意点2
            break;
        }
    }
    for (int j = 0; j < m; j++) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = 1;
        } else {                    //注意点3
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    result = dp[n - 1][m - 1];

    return result;
}

// 方法2.递归法，超时
int P0063_UniquePathsII::uniquePathsWithObstacles_2(vector<vector<int>> &obstacleGrid) {
    int result = 0;
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {     // 起点或终点是1，则返回0
        return 0;
    }

    dfs(obstacleGrid, n, m, 0, 0, result);
    return result;
}

void P0063_UniquePathsII::dfs(vector<vector<int>> &obstacleGrid, int n, int m, int x, int y, int &result) {
    if (x == n - 1 && y == m - 1) {
        result++;
    } else {
        if (x != n - 1) {   // 可以向下
            if (obstacleGrid[x + 1][y] != 1) {
                dfs(obstacleGrid, n, m, x + 1, y, result);
            }
        }
        if (y != m - 1) {   // 可以向右
            if (obstacleGrid[x][y + 1] != 1) {
                dfs(obstacleGrid, n, m, x, y + 1, result);
            }
        }
    }
}

int P0063_UniquePathsII::test() {
    vector<vector<int>> obstacleGrid = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    cout << uniquePathsWithObstacles_1(obstacleGrid) << endl;
    return 0;
}

