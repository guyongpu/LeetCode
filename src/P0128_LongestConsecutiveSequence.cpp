//
// Created by yongpu on 2019/12/2 9:02.
//

#include "P0128_LongestConsecutiveSequence.h"

/**
 * 题目：最长连续序列
 * 描述：给定一个未排序的整数数组，找出最长连续序列的长度.
 * 思路：将每个nums[i]-1不在序列中的数作为起点，然后进行遍历，能够保证比较时间复杂度为O(n)
 * 备注：暴力法/排序法时间复杂度较高
 */

int P0128_LongestConsecutiveSequence::longestConsecutive(vector<int> &nums) {
    if (nums.size() <= 1) {
        return nums.size();
    }
    unordered_set<int> myset(nums.begin(), nums.end());
    int result = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (myset.count(nums[i] - 1) == 0) {    //只有当nums[i]-1不在数组中，则说明nums[i]是一个序列的开始
            int next = nums[i] + 1;
            while (myset.count(next)) {
                next++;
            }
            result = max(result, next - nums[i]);
        }
    }
    return result;
}

int P0128_LongestConsecutiveSequence::test() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};  //4
    cout << longestConsecutive(nums) << endl;
    return 0;
}
