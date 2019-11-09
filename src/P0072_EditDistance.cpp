//
// Created by yongpu on 2019/11/9 14:02.
//

#include "P0072_EditDistance.h"

/**
 * 题目：编辑距离
 * 描述：给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数.
 * 思路：使用动态规划，dp[i][j]=1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]).
 * 备注：掌握动态转化方程.
 */

int P0072_EditDistance::minDistance(string word1, string word2) {
    // word1 -> word2
    int len1 = word1.length();
    int len2 = word2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // 初始化
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    // 开始递推
    // 如果两个子串的最后一个字母相同，word1[i-1] = word2[j-1]，则：D[i][j]=D[i−1][j−1]
    // 否则，word1[i] != word2[j]，D[i][j] = 1 + min(D[i - 1][j], D[i][j - 1], D[i - 1][j - 1])
    for (int i = 1; i <= len1; i++) {       // word1
        for (int j = 1; j <= len2; j++) {   // word2
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // 替换：dp[i-1][j-1] , 即dp[i-1][j-1]到 dp[i][j] 需要进行替换操作；
                // 删除：dp[i-1][j]   , 即dp[i-1][j]  到 d[i][j]  需要进行删除操作；
                // 插入：dp[i][j-1]   , 即dp[i][j-1]  到 d[i][j]  需要进行添加操作。
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    int result = dp[len1][len2];
    return result;
}

int P0072_EditDistance::test() {
    cout << minDistance("horse", "ros") << endl;  //3
    cout << minDistance("intention", "execution") << endl;  //5
    return 0;
}
