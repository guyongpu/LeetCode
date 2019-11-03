//
// Created by yongpu on 2019/11/3 19:40.
//

#include "P0053_MaximumSubarray.h"

int P0053_MaximumSubarray::maxSubArray(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) {
        return 0;
    }
    if (len == 1) {
        return nums[0];
    }
    int sum = nums[0];
    int start = 0;
    int end = 0;
    int temp_sum = sum;
    while (end < len) {
        //temp_sum
        temp_sum = temp_sum + nums[end];
        if(temp_sum < 0){

        }


    }

    return 0;
}

int P0053_MaximumSubarray::test() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
