//
// Created by yongpu on 2019/10/9.
//

#include "P0152_MaximumProductSubarray.h"

/**
 * 题目：乘积最大子序列
 * 描述：给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）.
 * 思路：令imax为当前最大值，imax = max(imax * nums[i], nums[i])由于存在负数，那么会导致最大的变最小的，最小的变最大的.
 * 因此还需要维护当前最小值，imin = min(imin * nums[i], nums[i])当负数出现时则imax与imin进行交换再进行下一步计算.
 * 备注：负数时要交换 tmin 和 tmax. *
 */

int P0152_MaximumProductSubarray::maxProduct(vector<int> &nums) {
    int len = nums.size();
    if (len == 0)
        return 0;

    int result = INT_MIN;
    int tmax = 1;
    int tmin = 1;
    for (int i = 0; i < len; i++) {

        // tmax 与 tmin 进行交换
        if(nums[i] < 0){
            int temp = tmax;
            tmax = tmin;
            tmin = temp;
        }

        tmax = max(tmax*nums[i], nums[i]);
        tmin = min(tmin*nums[i], nums[i]);

        result = max(result, tmax);
    }
    return result;
}

int P0152_MaximumProductSubarray::test() {
    vector<int> nums = {2, 3, -2, 4, 8, 9, 1, -1, 0, 5, 7, 2, 0, 1, 2, 3, 5, -8, 0};
    int result = maxProduct(nums);
    cout << result << endl;
    return 0;
}
