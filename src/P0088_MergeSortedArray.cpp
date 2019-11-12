//
// Created by yongpu on 2019/11/12 11:21.
//

#include "P0088_MergeSortedArray.h"

/**
 * 题目：合并两个有序数组
 * 描述：给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组.
 * 思路：m+n为总长度，从后往前，从nums[n+m-1]开始对nums1重写，i=[n-1,0],j=[m-1,0],倒序合并，避免重复交换等操作.
 * 备注：倒序合并
 */

void P0088_MergeSortedArray::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int len = m + n;
    int i = m - 1;
    int j = n - 1;

    int index = len - 1;
    while (i >= 0 || j >= 0) {
        if (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[index] = nums1[i];
                index--;
                i--;
            } else {
                nums1[index] = nums2[j];
                index--;
                j--;
            }
        } else if (i >= 0) {
            nums1[index] = nums1[i];
            index--;
            i--;
        } else {  // j >= 0
            nums1[index] = nums2[j];
            index--;
            j--;
        }
    }
}

int P0088_MergeSortedArray::test() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    for (int i = 0; i < 6; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
