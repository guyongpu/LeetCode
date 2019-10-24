//
// Created by yongpu on 2019/10/24 10:14.
//

#include "P0198_HouseRobber.h"

/**
 * 题目：打家劫舍
 * 描述：给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额.
 * 思路：方法1.动态规划dp[n] = MAX(dp[n-1], dp[n-2]+num);方法2.奇偶数之和，每次进行处理最优解.
 * 备注：掌握动态规划和奇偶数求和的方法
 */

// 方法1.动态规划方法
// 动态规划方程：dp[n] = MAX( dp[n-1], dp[n-2] + num )
int P0198_HouseRobber::rob_1(vector<int> &nums) {
    int nums_size = nums.size();
    if (nums_size == 0)
        return 0;
    vector<int> dp(nums_size + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 1; i < nums_size; i++) {
        int index = i + 1;
        dp[index] = max(dp[index-1],dp[index-2]+nums[i]);
    }

    int result = dp[nums_size];
    return result;
}


// 方法2.奇偶数方法
int P0198_HouseRobber::rob_2(vector<int> &nums) {
    int odd_sum = 0;
    int even_sum = 0;
    int nums_size = nums.size();

    for (int i = 0; i < nums_size; i++) {
        if (i % 2 == 1) {       //奇数和
            odd_sum = odd_sum + nums[i];
            odd_sum = max(odd_sum, even_sum);
        } else {                //偶数和
            even_sum = even_sum + nums[i];
            even_sum = max(odd_sum, even_sum);
        }
    }
    int result = max(odd_sum, even_sum);

    return result;
}

int P0198_HouseRobber::test() {
    vector<int> nums1 = {2, 7, 9, 3, 1};
    vector<int> nums2 = {2, 1, 1, 10};
    cout << rob_1(nums2) << endl;
    return 0;
}
