//
// Created by yongpu on 2019/10/13 10:33.
//

#include "P0081_SearchInRotatedSortedArrayII.h"

/**
 * 题目：搜索旋转排序数组 II
 * 描述：判断给定的目标值是否存在于旋转数组中。
 * 思路：套用旋转数组的解法，先判断nums[mid]的位置，然后再进一步比较nums[left]与target，不断缩小范围.
 * 备注：需要更加仔细处理.
 */

bool P0081_SearchInRotatedSortedArrayII::search(vector<int> &nums, int target) {
    int len = nums.size();
    if (len <= 0)
        return false;
    if (len == 1) {
        if (nums[len - 1] != target)
            return false;
        else
            return true;
    }

    //开始二分查找
    int left = 0;
    int right = len - 1;

    bool result = false;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target || nums[left] == target || nums[right] == target) {
            result = true;
            break;
        }

        if (nums[left] < nums[mid]) {           // nums[mid] 位于前半段
            if (target < nums[left]) {          // target 位于 [mid+1 ,right-1] 中
                left = mid + 1;
                right = right - 1;
            } else {                            // target 位于 [left+1 ,right-1] 中
                left = left + 1;
                right = right - 1;
            }

        } else if (nums[left] > nums[mid]) {    // nums[mid] 位于后半段
            if (target < nums[right]) {         // target 位于 [left+1 ,right-1] 中
                left = left + 1;
                right = right - 1;
            } else {                            // target 位于 [left+1 ,mid-1] 中
                left = left + 1;
                right = mid - 1;
            }

        } else {                                // nums[mid] 不确定，则需要直接查找 [left , right] 的范围
            // 在 [left , right]中查找
            for(int k = left; k <right ;k ++){
                if(nums[k] == target)
                {
                    result = true;
                    break;
                }
            }
            break;
        }
    }

    return result;
}

int P0081_SearchInRotatedSortedArrayII::test() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    cout << search(nums, 1) << endl;
    return 0;
}
