//
// Created by yongpu on 2019/10/27 17:13.
//

#include "P0044_WildcardMatching.h"

/**
 * 题目：通配符匹配
 * 描述：给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配.
 * 思路：回溯法（超时）或者动态规划方法。遇到？，直接匹配；如果遇到*，则考虑匹配0个，1个，多个.
 * 备注：掌握递归回溯和动态规划
 */


/**
 * （一）状态
 *      f[i][j]表示s1的前i个字符，和s2的前j个字符，能否匹配
 * （二）转移方程
 *      如果s1的第 i 个字符和s2的第 j 个字符相同，或者s2的第 j 个字符为 “?”，则dp[i][j] = dp[i - 1][j - 1]，各匹配一个字符，都往后移
 *      如果s2的第 j 个字符为 *
 *          2.1 若s2的第 j 个字符匹配空串, dp[i][j] = dp[i][j - 1]                即*不匹配任何字符，直接跳过*
 *          2.2 若s2的第 j 个字符匹配s1的第 i 个字符, dp[i][j] = dp[i - 1][j]      匹配一个
 *          2.3 若s2的第 j 个字符匹配s1的第 i 个字符, dp[i][j] = dp[i - 1][j - 1]  匹配多个，也可以不要这一步
 *      这里注意不是 f[i - 1][j - 1]， 举个例子就明白了 (abc, a*) dp[3][2] = dp[2][2]
 * （三）初始化
 *      dp[0][i] = dp[0][i - 1] && s2[i] == *
 *      即s1的前0个字符和s2的前i个字符能否匹配，或者说空字符串s1与字符串s2的匹配情况
 * （四）结果
 *      f[m][n]
 */

// 方法1：动态规划
bool P0044_WildcardMatching::isMatch_1(string s, string p) {
    int lens = s.length();
    int lenp = p.length();

    // dp[i][j]表示：s的前i个字符和p的前j个字符是否匹配
    vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));

    // 初始化dp[0][i]
    dp[0][0] = true;
    for (int i = 1; i <= lenp; i++) {
        if (p[i - 1] == '*' && dp[0][i - 1] == true) {
            dp[0][i] = true;
        }
    }

    for (int i = 1; i <= lens; i++) {           // s下标
        for (int j = 1; j <= lenp; j++) {       // p下标
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (p[j - 1] == '*') {
                // 匹配0个，1个，多个
                if (dp[i][j - 1] == true || dp[i - 1][j - 1] == true || dp[i - 1][j] == true) {
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp[lens][lenp];
}

// 方法2：递归回溯
bool P0044_WildcardMatching::isMatch_2(string s, string p) {
    string strp = dealStars(p);  //删除多余*
    p = strp;
    bool result = isMatch_sub(s, p, 0, 0);
    return result;
}

bool P0044_WildcardMatching::isMatch_sub(string s, string p, int is, int ip) {
    if (p.length() == ip) {
        if (s.length() == is) {
            return true;
        } else {
            return false;
        }
    }

    if (p.length() > ip && p[ip] == '*') {    //遇到*
        if (s.length() > is) {     // s长度能够继续往下移动
            bool flag1 = isMatch_sub(s, p, is + 1, ip);                 // s后移1位，p不动,多个
            if (flag1) {
                return true;
            }
            bool flag2 = isMatch_sub(s, p, is, ip + 1);                 // s不动，p后移1位，0个
            if (flag2) {
                return true;
            }
            bool flag3 = isMatch_sub(s, p, is + 1, ip + 1);          // s后移一位，p后移1位，1个
            if (flag3) {
                return true;
            }
        } else {
            bool flag4 = isMatch_sub(s, p, is, ip + 1);     // s不动，p后移1位
            if (flag4 == true) {
                return true;
            } else {
                return false;
            }
        }
    } else {
        if (s.length() > is && ((p[ip] == s[is]) || (p[ip] == '?'))) {
            bool flag5 = isMatch_sub(s, p, is + 1, ip + 1);     // s后移1位，p后移1位
            if (flag5 == true) {
                return true;
            } else {
                return false;
            }
        }
    }

    return false;
}

string P0044_WildcardMatching::dealStars(string p) {
    if (p.length() == 0)
        return p;
    string str = {p[0]};
    char prec = p[0];
    int len = p.length();
    for (int i = 1; i < len; i++) {
        if (prec == '*' && p[i] == '*') {
            continue;
        }
        str.push_back(p[i]);
        prec = p[i];
    }
    return str;
}

int P0044_WildcardMatching::test() {
    cout << isMatch_1("aa", "*") << endl;
    cout << isMatch_1("aa", "a") << endl;
    cout << isMatch_1("aa", "") << endl;
    cout << isMatch_1("", "") << endl;
    cout << isMatch_1("", "aa") << endl;
    cout << isMatch_1("aa", "a*") << endl;
    cout << isMatch_1("cb", "*a") << endl;
    cout << isMatch_1("cb", "?a") << endl;
    cout << isMatch_1("adceb", "*a*b") << endl;
    cout << isMatch_1("acdcb", "a*c?b") << endl;
    cout << isMatch_1("bbaaababbaaababababbb", "*a*****bb") << endl;
    cout << isMatch_1("abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab", "*aabb***aa**a******aa*") << endl;
    cout << isMatch_1(
            "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba",
            "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*") << endl;
    cout << isMatch_1(
            "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba",
            "*b*aba*babaa*bbaba*a*aaba*b*aa*a*b*ba*a*a*") << endl;

    return 0;
}