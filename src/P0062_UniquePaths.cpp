//
// Created by yongpu on 2019/11/5 15:53.
//

#include "P0062_UniquePaths.h"

/**
 * 题目：不同路径
 * 描述：一个机器人位于一个 m x n 网格的左上角（0,0),机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角(n-1,m-1),问总共有多少条不同的路径.
 * 思路：方法1.动态规划，dp[i][j]是到达 i, j 最多路径，则dp[i][j] = dp[i-1][j] + dp[i][j-1]；方法2.递归方法，会超时.
 * 备注：掌握方法1和方法2.
 */


/**
 * 方法1.动态规划
 * 我们令 dp[i][j] 是到达 i, j 最多路径
 * 动态方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 注意，对于第一行 dp[0][j]，或者第一列 dp[i][0]，由于都是在边界，所以只能为 1
 * 时间复杂度：O(m∗n)
 * 空间复杂度：O(m∗n)
 * 优化：因为我们每次只需要 dp[i-1][j],dp[i][j-1]
 * 所以我们只要记录这两个数，直接看代码吧！
*/
int P0062_UniquePaths::uniquePaths_1(int m, int n) {
    vector<vector<int>> dp(n, vector<int>(m, 0));    //dp[i][j] 是到达 i, j 最多路径
    // dp[i][0] = 1 和 dp[i][0] = 1
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int result = dp[n - 1][m - 1];

    return result;
}


// 方法2.递归法（超时）
int P0062_UniquePaths::uniquePaths_2(int m, int n) {
    int result = 0;
    dfs(m, n, 0, 0, result);
    return result;
}

void P0062_UniquePaths::dfs(int m, int n, int x, int y, int &result) {
    if (x == n - 1 && y == m - 1) {
        result++;
    } else {
        if (x != n - 1) {       //往下走
            dfs(m, n, x + 1, y, result);
        }
        if (y != m - 1) {       //往右走
            dfs(m, n, x, y + 1, result);
        }
    }
}

int P0062_UniquePaths::test() {
    cout << uniquePaths_1(3, 2) << endl;
    cout << uniquePaths_1(7, 3) << endl;
    cout << uniquePaths_1(1, 1) << endl;
    return 0;
}

