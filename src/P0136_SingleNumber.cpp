//
// Created by yongpu on 2019/10/13 14:57.
//

#include "P0136_SingleNumber.h"

/**
 * 题目：只出现一次的数字
 * 描述：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素.
 * 思路：两个相同的数异或等于0，因此将所有数进行异或，最后得到的数就是只出现一次的数.
 * 备注：常见题.
 */


int P0136_SingleNumber::singleNumber(vector<int> &nums) {
    int result = nums[0];
    int len = nums.size();
    for (int i = 1; i < len; i++) {
        result = result xor nums[i];
    }

    return result;
}

int P0136_SingleNumber::test() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 4, 3, 2, 1, 5};
    cout << singleNumber(nums) << endl;
    return 0;
}
