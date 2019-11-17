//
// Created by yongpu on 2019/11/14 22:00.
//

#include "P0091_DecodeWays.h"

/**
 * 题目：解码方法
 * 描述：给定一个只包含数字的非空字符串，请计算解码方法的总数.
 * 思路：使用动态规划，pre为dp[i-1]，curr为dp[i]，分为4种情况.
 * 备注：注意复习.
 */

// 动态规划
int P0091_DecodeWays::numDecodings(string s) {
    if (s[0] == '0')
        return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') {
                curr = pre;     // (1) dp[i] = do[i-1]
            } else {
                return 0;       // (2) return 0
            }
        } else if(((s[i - 1] - '0') * 10 + s[i] - '0' <= 26) && (s[i-1] != '0')) {  // s[i-1]s[i]<=26且s[i-1]!=0
            curr = curr + pre;  // (3) dp[i] = dp[i-1] + dp[i-2]
        }else{
            curr = curr;        // (4) dp[i] = dp[i-1]
        }
        pre = tmp;
    }
    return curr;
}

int P0091_DecodeWays::test() {
    cout << numDecodings("110") << endl;
    cout << numDecodings("100") << endl;
    cout << numDecodings("27") << endl;
    cout << numDecodings("10101") << endl;
    cout << numDecodings("1561234812") << endl;
    cout << numDecodings(
            "101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010")
         << endl;
    return 0;
}