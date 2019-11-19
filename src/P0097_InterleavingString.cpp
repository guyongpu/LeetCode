//
// Created by yongpu on 2019/11/19 16:28.
//

#include "P0097_InterleavingString.h"

/**
 * 题目：交错字符串
 * 描述：给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的.
 * 思路：方法1.递归回溯，但会超时；方法2.动态规划，dp[len1+1][len2+1]
 * 备注：掌握方法1和2
 */

// 方法1:递归回溯
bool P0097_InterleavingString::isInterleave_1(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
        return false;
    }
    if (s1.empty() || s2.empty()) {
        if ((s1.empty() && s2 != s3) || (s2.empty() && s1 != s3)) {
            return false;
        } else {
            return true;
        }
    }
    bool result = isInterleave_sub(s1, s2, s3, 0, 0, 0);

    return result;
}

bool P0097_InterleavingString::isInterleave_sub(string s1, string s2, string s3, int p1, int p2, int p3) {
    bool flag1 = false, flag2 = false;
    if (p1 == s1.length() && p2 == s2.length() && p3 == s3.length()) {
        return true;
    } else {
        if (p1 < s1.length()) {   // 使用p1匹配
            if (s1[p1] == s3[p3]) {
                flag1 = isInterleave_sub(s1, s2, s3, p1 + 1, p2, p3 + 1);
            }
        }
        if (flag1 == true) {
            return true;
        }
        if (p2 < s2.length()) {   // 使用p2匹配
            if (s2[p2] == s3[p3]) {
                flag2 = isInterleave_sub(s1, s2, s3, p1, p2 + 1, p3 + 1);
            }
        }
        if (flag2 == true) {
            return true;
        }
    }
    return false;
}

// 方法2.动态规划
bool P0097_InterleavingString::isInterleave_2(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
        return false;
    }
    if (s1.empty() || s2.empty()) {
        if ((s1.empty() && s2 != s3) || (s2.empty() && s1 != s3)) {
            return false;
        } else {
            return true;
        }
    }

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, false));

    dp[0][0] = true;

    for (int p1 = 1; p1 <= s1.length(); p1++) {
        if (s1[p1 - 1] == s3[p1 - 1] && dp[p1 - 1][0]) {       // s1的第p1个字符等于s3的对应字符，且dp[p1-1][0]为true
            dp[p1][0] = true;
        }
    }

    for (int p2 = 1; p2 <= s2.length(); p2++) {
        if (s2[p2 - 1] == s3[p2 - 1] && dp[0][p2 - 1]) {       // s2的第p2个字符等于s3的对应字符，且dp[0][p2-1]为true
            dp[0][p2] = true;
        }
    }

    for (int p1 = 1; p1 <= s1.length(); p1++) {
        for (int p2 = 1; p2 <= s2.length(); p2++) {
            // dp[p1][p2]
            if (s1[p1 - 1] == s3[p1 + p2 - 1] && dp[p1 - 1][p2]) {  // 采用s1匹配
                dp[p1][p2] = true;
            }
            if (s2[p2 - 1] == s3[p1 + p2 - 1] && dp[p1][p2 - 1]) {  // 采用s2匹配
                dp[p1][p2] = true;
            }
        }
    }

    bool result = dp[s1.length()][s2.length()];

    return result;
}


int P0097_InterleavingString::test() {
    cout << isInterleave_2("", "", "") << endl;       // true
    cout << isInterleave_2("aab", "dbb", "aadbbb") << endl;
    cout << isInterleave_2("db", "b", "cbb") << endl;
    cout << isInterleave_2("aabcc", "dbbca", "aadbbcbcac") << endl;       // true
    cout << isInterleave_2("aabcc", "dbbca", "aadbbbaccc") << endl;;      // false
    return 0;
}

