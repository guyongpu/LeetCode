//
// Created by yongpu on 2019/11/3 19:40.
//

#include "P0053_MaximumSubarray.h"

/**
 * 题目：最大子序和
 * 描述：给定一个整数数组 nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和.
 * 思路：遍历数组nums，当temp_sum<0时，更新temp_sum；当temp_sum>=0时，则累加，并更新sum.
 * 备注：掌握方法1和2，还有暴力法也可以.
 */

// 方法1：while遍历
int P0053_MaximumSubarray::maxSubArray_1(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) {
        return 0;
    }
    int sum = nums[0];
    int temp_sum = nums[0];
    int i = 0;
    while (1) {
        while (temp_sum < 0) {
            if (i + 1 < len) {
                temp_sum = nums[i + 1];     // 更新temp_sum
                sum = max(sum, temp_sum);   // 更新sum
                i++;
            } else {
                break;
            }
        }
        i++;
        if (i < len) {
            temp_sum = temp_sum + nums[i];  // 更新temp_sum
            sum = max(sum, temp_sum);       // 更新sum
        } else {
            break;
        }
    }
    return sum;
}

// 方法2：for遍历,更加简洁
int P0053_MaximumSubarray::maxSubArray_2(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) {
        return 0;
    }
    int sum = nums[0];
    int temp_sum = 0;
    for (int i = 0; i < len; i++) {
        if (temp_sum > 0) {
            temp_sum = temp_sum + nums[i];
        } else {
            temp_sum = nums[i];
        }
        sum = max(sum, temp_sum);
    }

    return 0;
}

int P0053_MaximumSubarray::test() {
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4, 6};
    vector<int> nums2 = {55, 0, -10, 5, 6, 8, 10};
    vector<int> nums3 = {55};
    cout << maxSubArray_1(nums3) << endl;
    return 0;
}

