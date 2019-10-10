//
// Created by yongpu on 2019/10/10.
//

#include "P0153_FindMinimumInRotatedSortedArray.h"

/**
 * 题目：寻找旋转排序数组中的最小值
 * 描述：假设按照升序排序的数组在预先未知的某个点上进行了旋转，请找出其中最小的元素。
 * 思路：此题是剑指Offer上原题，采用二分查找的思想做，每次用 num[start]与num[mid]比较，最终start指向最大元素，last指向最小元素
 * 备注：注意终止条件，start <last && start != mid 进行循环，否则结束查找
 */

int P0153_FindMinimumInRotatedSortedArray::findMin(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];

    int len = nums.size();
    if (nums[0] <= nums[len - 1]) {
        return nums[0];
    }

    //开始二分查找
    int start = 0;
    int last = len - 1;
    int mid = (start + last) / 2;
    while (start < last && start != mid) {  //循环终止条件，start != mid必须要加上
        if (nums[start] <= nums[mid]) {
            start = mid;
        } else {
            last = mid;
        }
        mid = (start + last) / 2;
    }
    int result = nums[last];

    return result;
}

int P0153_FindMinimumInRotatedSortedArray::test() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int result = findMin(nums);
    cout << result << endl;
    return 0;
}
