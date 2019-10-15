//
// Created by yongpu on 2019/10/14 13:26.
//

#include "P0016_3SumClosest.h"

/**
 * 题目：最接近的三数之和
 * 描述：给定一个包括n个整数的数组nums和一个目标值 target。找出nums中的三个整数，使得它们的和与 target 最接近.
 * 思路：套用三个数相加的思路，不过要注意找绝对值最小的.
 * 备注：left要从i+1开始
 */

int P0016_3SumClosest::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int result = INT_MAX;
    bool flag = false;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int left = i + 1;                   // 要从i+1开始
        int right = len - 1;
        int sum = target - nums[i];
        while (left < right) {
            int dif = sum - nums[left] - nums[right];
            if (abs(dif) < abs(result)) {   // 找绝对值最小的，即距离0最近的
                result = dif;
            }
            if (dif == 0) {                 // 相等，则可以提前结束
                flag = true;
                break;
            } else if (dif > 0) {
                left++;
            } else {
                right--;
            }

        }
        if (flag == true) {
            break;
        }
    }
    result = target - result;
    return result;
}

int P0016_3SumClosest::test() {
    vector<int> nums = {-1, 2, 1, 0, 6, 7, 3, -4};
    int result = threeSumClosest(nums, 19);
    cout << result << endl;
    return 0;
}
