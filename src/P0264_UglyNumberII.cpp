//
// Created by yongpu on 2019/12/30 21:41.
//

#include "P0264_UglyNumberII.h"

/**
 * 题目：丑数II
 * 描述：编写一个程序，找出第 n 个丑数。丑数就是只包含质因数 2, 3, 5 的正整数。
 * 思路：动态规划，使用三个指针，每个指针只有在dp[pos_x]*x是最小数的时候才会向右移动.也就是每个数都必须乘以2/3/5，然后对应指针才右移.
 * 备注：掌握该题目
 */

int P0264_UglyNumberII::nthUglyNumber(int n) {
    vector<int> dp = {1};
    int index = 1;
    int pos_2 = 0;
    int pos_3 = 0;
    int pos_5 = 0;

    while (index < n) {
        int num = min(min(dp[pos_2] * 2, dp[pos_3] * 3), dp[pos_5] * 5);
        if (dp[pos_2] * 2 == num) {
            pos_2++;
        }
        if (dp[pos_3] * 3 == num) {
            pos_3++;
        }
        if (dp[pos_5] * 5 == num) {
            pos_5++;
        }
        dp.push_back(num);
        index++;
    }

    return dp[n - 1];
}

int P0264_UglyNumberII::test() {
    cout << nthUglyNumber(5) << endl;
    cout << nthUglyNumber(10) << endl;
    return 0;
}
