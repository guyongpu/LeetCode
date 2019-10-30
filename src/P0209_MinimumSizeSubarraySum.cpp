//
// Created by yongpu on 2019/10/27 16:24.
//

#include "P0209_MinimumSizeSubarraySum.h"

/**
 * 题目：长度最小的子数组
 * 描述：给定一个含有n个正整数的数组和一个正整数s找出该数组中满足其和≥ s的长度最小的连续子数组.如果不存在符合条件的连续子数组，返回0.
 * 思路：采用滑动窗口的做法，start和end指针，当windSum>=s，则start后移；否则end后移，当windSum>=s时，计算result=min(result,end-start+1).
 * 备注：掌握滑动窗口做法.
 * 二分查找做法：计算sums[0....len-1]的值，然后遍历sums,例如确定sums[i] >= sum,则用二分查找一个最接近sum[i]-sum的值的下标,复杂度(O(nlongn)).
 */



int P0209_MinimumSizeSubarraySum::minSubArrayLen(int s, vector<int> &nums) {
    int result = 0;
    int start = 0;  //滑动窗口起始下标
    int end = 0;    //滑动窗口结束下标
    int windSum = 0;
    int numsSize = nums.size();

    for (int i = 0; i < numsSize; i++) {
        windSum = windSum + nums[i];
        end = i;
        if (windSum >= s) {
            break;
        }
    }
    if (windSum < s) {              // 如果所有数字和<s，则返回0
        return 0;
    }

    result = end - start + 1;       // 长度

    while (start < numsSize && end < numsSize) {
        if (windSum >= s) {         //满足windSum >= s，则计算result
            result = min(result, end - start + 1);
            if (result == 1) {      //如果result=1,则可以提前结束
                break;
            }
        }
        if (windSum >= s) {         //如果windSum>=s,则start往后移
            windSum = windSum - nums[start];
            start = start + 1;
        } else {                    //如果windSum<=s,则end往后移
            end = end + 1;
            if (end < numsSize) {
                windSum = windSum + nums[end];
            }
        }
    }
    return result;
}

int P0209_MinimumSizeSubarraySum::test() {
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    vector<int> nums2 = {0, 0, 0, 0, 0, 0};
    cout << minSubArrayLen(30, nums2) << endl;
    return 0;
}
