//
// Created by yongpu on 2019/10/13 11:17.
//

#include "P0164_MaximumGap.h"

/**
 * 题目：最大间距
 * 描述：给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值，如果数组元素个数小于 2，则返回 0.
 * 思路：排序+线性复杂度，则用桶排序思想，桶容量=(max-min)/len+1, 桶数量 = (max-min)/桶容量 +1；
 * 备注：桶排序思想，要复习
 */

int P0164_MaximumGap::maximumGap(vector<int> &nums) {
    int len = nums.size();
    if (len < 2) {
        return 0;
    }
    if (len == 2) {
        return abs(nums[1] - nums[0]);
    }

    // 计算最大/最小值
    int Max = nums[0];
    int Min = nums[0];
    for (int i = 0; i < len; i++) {
        Max = max(Max, nums[i]);
        Min = min(Min, nums[i]);
    }

    int bucketSize = (Max - Min) / len + 1;     //桶的容量
    int bucketNum = (Max - Min) / bucketSize + 1;       //桶的数量

    vector<int> bucket_min(bucketNum, INT_MAX);
    vector<int> bucket_max(bucketNum, INT_MIN);
    vector<bool> bucket_flag(bucketNum, false);   //是否使用过

    for (int i = 0; i < len; i++) {                     //装桶
        //判断nums[i]在哪个桶
        int index = (nums[i] - Min) / bucketSize;
        bucket_min[index] = min(bucket_min[index], nums[i]);
        bucket_max[index] = max(bucket_max[index], nums[i]);
        bucket_flag[index] = true;
    }

    int result = INT_MIN;

    if (Max == Min) {       //Max = Min,说明全部相等
        result = 0;
    } else {                //取当前桶的最小值与前一个桶的最大值的差值
        int indexPre = 0;
        for (int i = 1; i < bucketNum; i++) {
            if (bucket_flag[i] == true) {
                result = max(result, bucket_min[i] - bucket_max[indexPre]);
                indexPre = i;
            }
        }
    }
    return result;
}

int P0164_MaximumGap::test() {
    vector<int> nums = {1, 2, 3, 3};
    cout << maximumGap(nums) << endl;
    return 0;
}
