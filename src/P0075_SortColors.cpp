//
// Created by yongpu on 2019/11/9 20:08.
//

#include "P0075_SortColors.h"

/**
 * 题目：颜色分类
 * 描述：给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列.
 * 思路：沿着数组移动 curr 指针，若nums[curr] = 0，则将其与 nums[p0]互换；若 nums[curr] = 2 ，则与 nums[p2]互换.
 * 备注：双指针+交换
 */

void P0075_SortColors::sortColors(vector<int> &nums) {
    // 红色---白色---蓝色
    int len = nums.size();
    if (len <= 1) {
        return;
    }
    int p_0 = 0;
    int p_2 = len - 1;
    int curr = 0;
    while (curr <= p_2) {
        if (nums[curr] == 0) {
            swap(nums[p_0], nums[curr]);
            curr++;
            p_0++;
        } else if (nums[curr] == 2) {
            swap(nums[curr], nums[p_2]);
            p_2--;
        } else {
            curr++;
        }
    }
}

int P0075_SortColors::test() {
    vector<int> nums = {1,2,0};
    sortColors(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
