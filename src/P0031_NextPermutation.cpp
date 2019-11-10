//
// Created by yongpu on 2019/10/22 17:08.
//

#include "P0031_NextPermutation.h"

/**
 * 题目：下一个排列
 * 描述：实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列
 * 思路：分三个步骤,(1)找一组数nums[i-1]<nums[i];(2)找到nums[i-1]<nums[j],进行交换;(3)翻转nums[i-1]之后的序列.
 * 备注：这个题要掌握做法
 */

void P0031_NextPermutation::nextPermutation(vector<int> &nums) {
    int numSize = nums.size();
    if (numSize <= 1)
        return;
    // 判断是否已经是降序，如果是则翻转
    for (int i = 1; i < numSize; i++) {
        if (nums[i - 1] >= nums[i]) {
            if (i == numSize - 1) {
                sort(nums.begin(), nums.end());
                return;
            }
        } else {
            break;
        }
    }

    // (1)找一组数nums[i-1]<nums[i]
    int index = 0;  // index与index+1
    for (int i = numSize - 1; i >= 0; i--) {
        if (nums[i - 1] < nums[i]) {
            index = i - 1;
            break;
        }
    }

    // (2)向后找一个数，找到nums[i-1]<nums[j],进行交换;
    int index2 = 0;
    for (int i = index + 1; i < numSize; i++) {
        if (nums[index] < nums[i]) {
            index2 = i;
        }
    }
    swap(nums[index], nums[index2]);

    // (3)翻转nums[i-1]之后的序列.
    reverse(nums.begin() + index + 1, nums.end());
}

int P0031_NextPermutation::test() {
//    vector<int> nums = {8, 4, 7, 6, 5, 3, 1};
    vector<int> nums = {1, 3, 2};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
