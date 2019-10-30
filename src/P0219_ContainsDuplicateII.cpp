//
// Created by yongpu on 2019/10/28 18:59.
//

#include "P0219_ContainsDuplicateII.h"

/**
 * 题目：存在重复元素II
 * 描述：给定一个整数数组和一个整数k，判断数组中是否存在两个不同的索引i和j，使得nums[i]=nums[j]，并且i和j的差的绝对值最大为k.
 * 思路：滑动窗口思想，要求|j-i|<=k,因此维护一个k+1大小的滑动窗口，判断nums[i]是否存在与当前滑动窗口内，存在则返回true.
 * 备注：窗口大小为k+1，当size=k+1时，先删除nums[i-k-1]，再判断是否重复.
 */

bool P0219_ContainsDuplicateII::containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, bool> numsMap;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (numsMap.size() == k + 1) {      //如果大小已达到k+1
            numsMap.erase(nums[i - k - 1]); //先删除nums[i-k-1]，再进行重复判断
        }
        if (numsMap[nums[i]] == true) {
            return true;
        } else {
            numsMap[nums[i]] = true;
        }
    }
    return false;
}

int P0219_ContainsDuplicateII::test() {
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    cout << containsNearbyDuplicate(nums, 3) << endl;
    return 0;
}
