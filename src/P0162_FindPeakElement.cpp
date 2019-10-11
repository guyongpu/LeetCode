//
// Created by yongpu on 2019/10/11 10:22.
//

#include "P0162_FindPeakElement.h"

/** 题目：寻找峰值
 *  描述：峰值元素是指其值大于左右相邻值的元素,输入数组nums，相邻元素不相等，找到峰值元素并返回其索引,要求时间复杂度O(logN)
 *  思路：使用二分查找，不断比较nums[mid]与nums[mid + 1]，直到循环结束.
 *  备注：此题要复习
 */

int P0162_FindPeakElement::findPeakElement(vector<int> &nums) {
    if (nums.size() == 0)
        return -1;      //错误情况
    if (nums.size() == 1)
        return 0;

    //开始二分查找
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    int result = right;
    return result;
}

int P0162_FindPeakElement::test() {
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;
    return 0;
}
