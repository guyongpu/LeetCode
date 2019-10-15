//
// Created by yongpu on 2019/10/14 19:26.
//

#include "P0169_MajorityElement.h"

/**
 * 题目：求众数
 * 描述：给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素.
 * 思路：使用士兵攻城思想，设置计数器，相同的时候cnt+1，不同则cnt-1，当cnt=0,则设置nums[i]为新的士兵，最后的士兵就是众数.
 * 备注：求出现次数超过一半的数.
 */

int P0169_MajorityElement::majorityElement(vector<int> &nums) {
    int len = nums.size();
    int result = nums[0];
    int cnt = 1;
    for (int i = 1; i < len; i++) {
        if (result == nums[i]) {
            cnt++;
        } else {
            cnt--;
            if (cnt == 0) {
                result = nums[i];
                cnt = 1;
            }
        }

    }
    return result;
}

int P0169_MajorityElement::test() {
    vector<int> nums = {1, 2, 3, 4, 5, 3, 3, 3, 3};
    int result = majorityElement(nums);
    cout << result << endl;
    return 0;
}
