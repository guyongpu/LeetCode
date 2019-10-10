//
// Created by yongpu on 2019/10/10 20:39.
//

#include "P0154_FindMinimumInRotatedSortedArrayII.h"

/**
 * 题目：寻找旋转排序数组中的最小值 II
 * 描述：假设按照升序排序的数组在预先未知的某个点上进行了旋转，请找出其中最小的元素，注意数组中可能存在重复的元素.
 * 思路：在二分查找的思路下，考虑重复元素的情况，如果遇到相等情况，无法判断mid处的位置，只能在[start , last]之间遍历查找
 * 备注：注意初始化 minNumTemp，以及考虑重复元素
 */

int P0154_FindMinimumInRotatedSortedArrayII::findMin(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];

    int len = nums.size();
    if (nums[0] < nums[len - 1])
        return nums[0];

    //开始二分查找
    int start = 0;
    int last = len - 1;
    int mid = (start + last) / 2;

    int result = 0;
    int minNumTemp = nums[start];       //必须初始化，不然遇到[3,3]的情况会出错
    while (start < last && start != mid) {
        if (nums[start] < nums[mid]) {
            start = mid;
            mid = (start + last) / 2;
        } else if (nums[start] > nums[mid]) {
            last = mid;
            mid = (start + last) / 2;
        } else {                    //考虑重复的情况
            //直接在[start , last]间查找最小值
            minNumTemp = nums[start];
            for (int i = start; i <= last; i++) {
                minNumTemp = min(minNumTemp, nums[i]);
            }
            break;
        }
    }

    result = min(nums[last], minNumTemp);

    return result;
}

int P0154_FindMinimumInRotatedSortedArrayII::test() {
    vector<int> nums = {1,1};
    cout << findMin(nums) << endl;
    return 0;
}
