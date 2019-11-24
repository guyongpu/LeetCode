//
// Created by yongpu on 2019/11/22 21:50.
//

#include "P0115_DistinctSubsequences.h"

/**
 * 题目：不同子序列
 * 描述：给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数.
 * 思路：使用动态规划方法，设计动态规划方程，完成计算.
 * 备注：掌握动态规划方程.
 */

/**
 * 动态规划
 * dp[i][j] 代表T前i字符串可以由S的j字符串组成最多个数.
 *
 * 所以动态方程:
 * 当 S[j] == T[i] , dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
 * 当 S[j] != T[i] , dp[i][j] = dp[i][j-1]
 *
 * 举个例子,如示例的
 * 对于第一行, T 为空,因为空集是所有字符串子集, 所以我们第一行都是 1
 * 对于第一列, S 为空,这样组成 T 个数当然为 0 了
 * 至于下面如何进行,大家可以通过动态方程,自行模拟一下!
 */

int P0115_DistinctSubsequences::numDistinct(string s, string t) {
    int lens = s.size();
    int lent = t.size();
    if (lens < lent) {
        return 0;
    }

    vector<vector<int>> dp(lent + 1, vector<int>(lens + 1)); // dp[i][j] -- t[i]s[j]

    // 第一行
    for (int j = 0; j < lens + 1; j++) {
        dp[0][j] = 1;
    }

    // 第一列
    for (int i = 1; i < lent + 1; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i < lent + 1; i++) {
        for (int j = 1; j < lens + 1; j++) {
            if (t[i - 1] == s[j - 1]) {
                // 因为返回值是int，所以dp[i][j]如果超过INT_MAX，肯定是无效解，因此在这里将dp[i][j] 置为 INT_MAX即可.
                if (dp[i - 1][j - 1] + dp[i][j - 1] > INT_MAX) {
                    dp[i][j] = INT_MAX;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    int result = dp[lent][lens];
    return result;
}

int P0115_DistinctSubsequences::test() {
    cout << numDistinct("rabbbit", "rabbit") << endl;
    cout << numDistinct("babgbag", "bag") << endl;
    return 0;
}
