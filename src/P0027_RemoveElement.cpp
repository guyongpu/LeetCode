//
// Created by yongpu on 2019/10/18 16:41.
//

#include "P0027_RemoveElement.h"

/**
 * 题目：移除元素
 * 描述：给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度.
 * 思路：用双指针做法，一个指针用做遍历指针i，另一个用作实际元素下标index，当不相等时index++,遍历结束index为长度.
 * 备注：双指针做法.
 */

int P0027_RemoveElement::removeElement(vector<int> &nums, int val) {
    int index = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (nums[i] == val) { ;
        } else {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int P0027_RemoveElement::test() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int result = removeElement(nums, 20);
    cout << result << endl;
    return 0;
}
