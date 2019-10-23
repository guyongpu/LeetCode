//
// Created by yongpu on 2019/10/23 16:41.
//

#include "P0035_SearchInsertPosition.h"

/**
 * 题目：搜索插入位置
 * 描述：给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置.
 * 思路：先处理一些特殊情况，然后套用二分查找模板进行计算.最后比较nums[mid]的关系，返回正确的下标.
 * 备注：返回下标要仔细.
 */

int P0035_SearchInsertPosition::searchInsert(vector<int> &nums, int target) {
    // 处理一些特殊情况
    if (nums.size() == 0)       // nums为空，直接返回0
        return 0;
    if (nums[0] >= target) {    // target <= nums[0]，则直接返回0
        return 0;
    }
    if (nums[nums.size() - 1] == target) {  // target = nums最后元素，则直接返回最后元素的下标
        return nums.size() - 1;
    }
    if (nums[nums.size() - 1] < target) {   // target > nums最后元素，则直接返回最后元素的下标+1，即长度
        return nums.size();
    }

    // 开始二分查找
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
//    cout << low << " " << mid << " " << high << endl;
    if (target < nums[mid]) {       // target < nums[mid]，说明target应该插入到mid位置
        return mid;
    } else {                        // target > nums[mid],说明target应该插入到mi即后面，即mid+1
        return mid + 1;
    }

}

int P0035_SearchInsertPosition::test() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 10};
    cout << searchInsert(nums1, 7) << endl;
    return 0;
}
