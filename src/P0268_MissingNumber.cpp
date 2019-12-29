//
// Created by yongpu on 2019/12/29 17:44.
//

#include "P0268_MissingNumber.h"

/**
 * 题目：缺失数字
 * 描述：给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数.
 * 思路：方法1.高斯求和法；方法2.异或法；方法3.排序对比法
 * 备注：掌握三种方法
 */

// 方法1.高斯求和法
int P0268_MissingNumber::missingNumber_1(vector<int> &nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum = sum + nums[i];
    }

    int len = nums.size();
    int sum_temp = (0 + len) * (len + 1) / 2;
    return sum_temp - sum;
}

// 方法2.异或法
int P0268_MissingNumber::missingNumber_2(vector<int> &nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result = result xor nums[i];
    }

    for(int i = 0 ;i < nums.size()+1;i++){
        result = result xor i;
    }
    return result;
}

int P0268_MissingNumber::test() {
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber_1(nums) << endl;
    cout << missingNumber_2(nums) << endl;
    return 0;
}