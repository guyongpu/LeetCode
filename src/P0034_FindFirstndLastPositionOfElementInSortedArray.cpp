//
// Created by yongpu on 2019/10/23 17:20.
//

#include "P0034_FindFirstndLastPositionOfElementInSortedArray.h"

/**
 * 题目：在排序数组中查找元素的第一个和最后一个位置
 * 描述：给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置，要求O(log n)
 * 思路：方法1：直接遍历;2.二分查找+左右遍历;3.二分查找+二分查找左下标+二分查找右下标.
 * 备注：方法1,2会超时，掌握方法3
 */

vector<int> P0034_FindFirstndLastPositionOfElementInSortedArray::searchRange(vector<int> &nums, int target) {
    int pos1 = -1, pos2 = -1;
    vector<int> result;

    //step1.二分查找target是否存在
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (target == nums[mid]) {
            //step1.寻找target最小左下标
            int low_1 = low;
            int high_1 = mid;
            int mid_1;
            while (low_1 <= high_1) {
                mid_1 = (low_1 + high_1) / 2;
                if (nums[mid_1] == target) {
                    pos1 = mid_1;
                    high_1 = mid_1 - 1;
                } else if (nums[mid_1] < target) {
                    low_1 = mid_1 + 1;
                }
            }

            //step3.寻找target最大右下标
            int low_2 = mid;
            int high_2 = high;
            int mid_2;
            while (low_2 <= high_2) {
                mid_2 = (low_2 + high_2) / 2;
                if (nums[mid_2] == target) {
                    pos2 = mid_2;
                    low_2 = mid_2 + 1;
                } else if (nums[mid_2] > target) {
                    high_2 = mid_2 - 1;
                }
            }
            break;
        } else if (target < nums[mid]) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        }

    }
    result.push_back(pos1);
    result.push_back(pos2);
    return result;
}

int P0034_FindFirstndLastPositionOfElementInSortedArray::test() {
    vector<int> nums = {5, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 10};
    vector<int> result = searchRange(nums, 8);
    if (!result.empty())
        cout << result[0] << " " << result[1] << endl;
    return 0;
}
