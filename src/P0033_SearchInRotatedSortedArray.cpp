//
// Created by yongpu on 2019/10/23 19:14.
//

#include "P0033_SearchInRotatedSortedArray.h"

/**
 * 题目：搜索旋转排序数组
 * 描述：搜索一个给定的目标值，如果旋转数组中存在这个目标值，则返回它的索引，否则返回-1
 * 思路：二分查找思想，先nums[left]与nums[mid]比较，确定mid前后位置，然后缩小区间
 * 备注：无重复元素,重要题目.
 */

int P0033_SearchInRotatedSortedArray::search(vector<int> &nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target == nums[low]) {
            return low;
        } else if (target == nums[high]) {
            return high;
        }
        if (nums[low] < nums[mid]) {        //nums[mid]位于前半段
            if (target < nums[low]) {       // target 位于 [mid+1 ,right-1] 中
                low = mid + 1;
                high = high - 1;
            } else {                        // target 位于 [left+1 ,right-1] 中
                low = low + 1;
                high = high - 1;
            }
        } else {
            if (target < nums[high]) {      //nums[mid]位于后半段
                low = low + 1;              // target 位于 [left+1 ,right-1] 中
                high = high - 1;
            } else {                        // target 位于 [left+1 ,mid-1] 中
                low = low + 1;
                high = mid - 1;
            }
        }
    }
    return -1;
}

int P0033_SearchInRotatedSortedArray::test() {
    vector<int> nums1 = {14, 15, 16, 17, 18, 29, 100, 1, 5, 6, 7, 9};
    cout << search(nums1, 1) << endl;
    vector<int> nums2 = {1, 3, 5};
    cout << search(nums2, 5) << endl;
    vector<int> nums3 = {1, 2, 3, 4, 5, 6};
    cout << search(nums3, 4) << endl;
    return 0;
}
