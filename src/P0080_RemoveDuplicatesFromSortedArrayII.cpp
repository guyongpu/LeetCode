//
// Created by yongpu on 2019/11/11 9:13.
//

#include "P0080_RemoveDuplicatesFromSortedArrayII.h"

/**
 * 题目：删除排序数组中的重复项II
 * 描述：给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度.
 * 思路：采用一个index作为实际下标，另一个为遍历下标，然后后面的值覆盖前面的.
 * 备注：双指针做法
 */


int P0080_RemoveDuplicatesFromSortedArrayII::removeDuplicates(vector<int> &nums) {
    int len = nums.size();
    if (len <= 2) {
        return len;
    }

    int index = 1;
    for (int i = 2; i < len; i++) {
        if (nums[i] == nums[index]) {               // 如果nums[i]与nums[index]相等
            if (nums[index] == nums[index - 1]) {   // 如果nums[index]与nums[index-1]相等，说明三个相等，i继续向后
                continue;
            } else {                                // 如果nums[index]与nums[index-1]不相等，则index++，覆盖数组值
                index++;
                nums[index] = nums[i];
            }
        } else {                                    // 如果nums[i]与nums[index]相等，修改数组
            index++;
            nums[index] = nums[i];
        }
    }
    return index + 1;                               // 个数为index+1
}

int P0080_RemoveDuplicatesFromSortedArrayII::test() {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicates(nums) << endl;
    return 0;
}
