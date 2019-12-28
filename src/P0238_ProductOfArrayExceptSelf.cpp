//
// Created by yongpu on 2019/12/28 21:36.
//

#include "P0238_ProductOfArrayExceptSelf.h"

/**
 * 题目：除自身以外数组的乘积
 * 描述：给定长度为n的整数数组nums，返回输出数组 output，其中output[i]等于nums中除nums[i]之外其余各元素的乘积.
 * 思路：乘积 = 当前数左边的乘积 * 当前数右边的乘积
 * 备注：掌握方法
 */

vector<int> P0238_ProductOfArrayExceptSelf::productExceptSelf(vector<int> &nums) {
    int len = nums.size();
    vector<int> res(len);
    int k = 1;
    // 左边乘积为k，将k存入res[i]中
    for (int i = 0; i < len; i++) {
        res[i] = k;
        k = k * nums[i];        // 此时数组存储的是除去当前元素左边的元素乘积
    }

    k = 1;
    // 右边乘积为K，又因为res[i]记录左边的乘积，所以res[i] = res[i] * k
    for (int i = len - 1; i >= 0; i--) {
        res[i] = res[i] * k;    // k为该数右边的乘积
        k = k * nums[i];        // 此时数组等于左边的 * 该数右边的
    }

    return res;
}

int P0238_ProductOfArrayExceptSelf::test() {
    vector<int> nums = {7, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
