//
// Created by yongpu on 2019/12/4 16:13.
//

#include "P0132_PalindromePartitioningII.h"

/**
 * 题目：分割回文串II
 * 描述：给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串，返回符合要求的最少分割次数.
 * 思路：使用动态规划方法求解，f[i] = min(f[i] , f[j] + 1)
 * 备注：动态规划方法
 */

/**
 * （一）状态
 *      f[i]表示前 i 个字符组成的子串，最少需要几次分割，才能变成都是回文串
 * （二）转移方程
 *      对于所有的 j < i， 如果s[j, i]是回文串, 且 f[j] + 1 < f[i] 则 f[i] = f[j] + 1
 * （三）初始化
 *      f[i] = i - 1 ， 长度为 i 的子串，最多切 i - 1 次，都变成单个字符，就是回文串了
 * （四）结果
 *      f[n]
 */

bool detect(string str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if(str[left]!= str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int P0132_PalindromePartitioningII::minCut(string s) {
    int len = s.length();
    vector<int> dp(len + 1, 0);
    for (int i = 0; i <= len; i++) {
        dp[i] = i;
        for (int j = 0; j < i; j++) {
            string temp = s.substr(j, i - j);
            if (detect(temp)) {
                dp[i] = min(dp[j] + 1, dp[i]);
            }
        }
    }
    int resutl = dp[len] - 1;

    return resutl;
}

int P0132_PalindromePartitioningII::test() {
    cout << minCut("abbab") << endl;
    cout << minCut("aaaab") << endl;
    return 0;
}
