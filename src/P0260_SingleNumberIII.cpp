//
// Created by yongpu on 2019/10/13 16:24.
//

#include "P0260_SingleNumberIII.h"

/**
 * 题目:只出现一次的数字III
 * 描述：给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素.
 * 思路：将所有数字进行异或得到res，找到res中为1的位index，则num1在第index位为1，num2在第index位为0，分两类异或，得到结果.
 * 备注：系列I、II、III都要掌握.
 */

vector<int> P0260_SingleNumberIII::singleNumber(vector<int> &nums) {
    int len = nums.size();

    //计算异或结果
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res xor nums[i];
    }

    //找res中为1的位，则num1的第i位为1，num2的第i位为0
    int index = 0;
    for (int i = 0; i < 32; i++) {
        if (((res >> i) & 1) == 1) {
            index = i;
            break;
        }
    }
//    cout << index << endl;

    //将nums[i]第index位为0的一类，为1的当做另外一类
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < len; i++) {
        if (((nums[i] >> index) & 1) == 1) {
            num1 = num1 xor nums[i];
        } else {
            num2 = num2 xor nums[i];
        }
    }

    vector<int> result;
    result.push_back(num1);
    result.push_back(num2);
    return result;
}

int P0260_SingleNumberIII::test() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = singleNumber(nums);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
