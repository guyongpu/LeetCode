//
// Created by yongpu on 2019/10/23 20:26.
//

#include "P0189_RotateArray.h"

/**
 * 题目：旋转数组
 * 描述：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数.
 * 思路：方法1.每次旋转一位；方法2.翻转思想,BA = (B^T+A^T)^T
 * 备注：重点掌握翻转思想
 */


void P0189_RotateArray::rotate_1(vector<int> &nums, int k) {
    if (k == 0) {
        return;
    }
    // BA = (B^T+A^T)^T
    int len = nums.size();
    k = k % len;
    reverse(nums.begin(), nums.begin() + len - k);
    reverse(nums.begin() + len - k, nums.end());
    reverse(nums.begin(), nums.end());
}

void P0189_RotateArray::rotate_2(vector<int> &nums, int k) {
    if (k == 0) {
        return;
    }
    int len = nums.size();
    k = k % len;
    for (int i = 0; i < k; i++) {
        for (int i = len - 1; i >= 1; i--) {
            swap( nums[i-1],nums[i]);
        }
        /*
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;*/
    }

}

int P0189_RotateArray::test() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate_1(nums, 10);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
