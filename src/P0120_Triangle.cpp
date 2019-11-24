//
// Created by yongpu on 2019/11/23 21:42.
//

#include "P0120_Triangle.h"

/**
 * 题目：三角形的最小路径和
 * 描述：给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上.
 * 思路：方法1.DFS深度优先搜索，会超时；方法2.采用动态规划，自底向上，dpTable[j]的来源只有 dpTable[j] 或者 dpTable[j + 1].
 * 备注：掌握方法1和方法2
 */

/***********************************************************************************/
// 动态规划
// 这是一个典型的动态规划，状态转移方程如下：n表示row，c表示column。
//
//             |= triangle[n-1,c]       如果 n-1 是最后一行
// f(n-1, c) --|
//             |= min{f(n,c) + triangle[n-1,c], f(n,c+1) + triangle[n-1,c]}
//
int P0120_Triangle::minimumTotal(vector<vector<int>> &triangle) {
    vector<int> dpTable(triangle.back());

    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // 自底向上，dpTable[j]的来源只有 dpTable[j] 或者 dpTable[j + 1]
            dpTable[j] = min((dpTable[j] + triangle[i][j]), dpTable[j + 1] + triangle[i][j]);
        }
    }
    return dpTable[0];
}



/***********************************************************************************/
// 递归

void dfs(vector<vector<int>> &triangle, int pos_i, int pos_j, int temp, int &result) {
    if (pos_i == triangle.size()) {
        result = min(result, temp);
    } else {
        temp = temp + triangle[pos_i][pos_j];

        dfs(triangle, pos_i + 1, pos_j + 1, temp, result);
        dfs(triangle, pos_i + 1, pos_j, temp, result);
    }
}

int P0120_Triangle::minimumTotal_2(vector<vector<int>> &triangle) {
    int result = INT_MAX;

    dfs(triangle, 0, 0, 0, result);

    return result;
}

/***********************************************************************************/

int P0120_Triangle::test() {
    vector<vector<int>> triangle1 = {
            {2},
            {3, 4},
            {6, 5, 8},
            {4, 1, 8, 3},
    };

    vector<vector<int>> triangle = {
            {-1},
            {3,  2},
            {-3, 1, -1},
    };

    cout << minimumTotal(triangle1) << endl;

    return 0;
}
