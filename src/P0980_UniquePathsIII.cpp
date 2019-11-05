//
// Created by yongpu on 2019/11/5 17:24.
//

#include "P0980_UniquePathsIII.h"

/**
 * 题目：不同路径III
 * 描述：返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目，每一个无障碍方格都要通过一次.
 * 思路：使用递归回溯法，对走过的路径进行标记，回溯时取消标记，同时记录走过的空格数量，到终点且数量相等时符合要求.
 * 备注：熟练递归方法.
 */

void P0980_UniquePathsIII::dfs(vector<vector<int>> grid, int n, int m, int x, int y, vector<vector<bool>> &visitFlag,
                               int cntOf0, int stepCnt,
                               int &result) {
    if (grid[x][y] == 2) {          // 遇到终点
        if (stepCnt == cntOf0) {    // 确保所有的无障碍空格都已经访问过
            result++;
        }
    } else {
        if (grid[x][y] == 0) {      // 当遇到0的空方格，计数器+1
            stepCnt++;
        }
        visitFlag[x][y] = false;    //标记当前的路

        if (x > 0 && visitFlag[x - 1][y] == true && grid[x - 1][y] != -1) {        // 向上
            dfs(grid, n, m, x - 1, y, visitFlag, cntOf0, stepCnt, result);
        }
        if (x < n - 1 && visitFlag[x + 1][y] == true && grid[x + 1][y] != -1) {    // 向下
            dfs(grid, n, m, x + 1, y, visitFlag, cntOf0, stepCnt, result);
        }
        if (y > 0 && visitFlag[x][y - 1] == true && grid[x][y - 1] != -1) {       // 向左
            dfs(grid, n, m, x, y - 1, visitFlag, cntOf0, stepCnt, result);
        }
        if (y < m - 1 && visitFlag[x][y + 1] == true && grid[x][y + 1] != -1) {   // 向右
            dfs(grid, n, m, x, y + 1, visitFlag, cntOf0, stepCnt, result);
        }

        visitFlag[x][y] = true;    // 取消标记当前的路
    }
}


// 第二种写法
void P0980_UniquePathsIII::dfs_2(vector<vector<int>> grid, int n, int m, int x, int y, vector<vector<bool>> &visitFlag,
                                 int cntOf0, int stepCnt,
                                 int &result) {
    if (grid[x][y] == 2) {          // 遇到终点
        if (stepCnt == cntOf0) {    // 确保所有的无障碍空格都已经访问过
            result++;
        }
    } else {
        if (grid[x][y] == 0) {      // 当遇到0的空方格，计数器+1
            stepCnt++;
        }
        visitFlag[x][y] = false;    //标记当前的路
        if (x > 0 && visitFlag[x - 1][y] == true && grid[x - 1][y] != -1) {        // 向上
            visitFlag[x - 1][y] = false;
            dfs(grid, n, m, x - 1, y, visitFlag, cntOf0, stepCnt, result);
            visitFlag[x - 1][y] = true;
        }
        if (x < n - 1 && visitFlag[x + 1][y] == true && grid[x + 1][y] != -1) {    // 向下
            visitFlag[x + 1][y] = false;
            dfs(grid, n, m, x + 1, y, visitFlag, cntOf0, stepCnt, result);
            visitFlag[x + 1][y] = true;
        }
        if (y > 0 && visitFlag[x][y - 1] == true && grid[x][y - 1] != -1) {       // 向左
            visitFlag[x][y - 1] = false;
            dfs(grid, n, m, x, y - 1, visitFlag, cntOf0, stepCnt, result);
            visitFlag[x][y - 1] = true;
        }
        if (y < m - 1 && visitFlag[x][y + 1] == true && grid[x][y + 1] != -1) {   // 向右
            visitFlag[x][y + 1] = false;
            dfs(grid, n, m, x, y + 1, visitFlag, cntOf0, stepCnt, result);
            visitFlag[x][y + 1] = true;
        }
    }
}


int P0980_UniquePathsIII::uniquePathsIII(vector<vector<int>> &grid) {
    int result = 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visitFlag(n, vector<bool>(m, true));   //不然会溢出
    int start_x = 0;    // 起点坐标x
    int start_y = 0;    // 起点坐标y
    int cntOf0 = 0;     // 空格数量
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {  // 找到起点
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == 0) {  // 经过空格
                cntOf0++;
            }
        }
    }
    dfs(grid, n, m, start_x, start_y, visitFlag, cntOf0, 0, result);

    return result;
}

int P0980_UniquePathsIII::test() {
    vector<vector<int>> grid1 = {{1, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 2, -1}};    //2

    vector<vector<int>> grid2 = {{1, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 2}};     //4

    vector<vector<int>> grid3 = {{1, 0,  0,  0},
                                 {0, 0,  -1, 0},
                                 {0, -1, 0,  2}};   //0
    cout << uniquePathsIII(grid2) << endl;
    return 0;
}
