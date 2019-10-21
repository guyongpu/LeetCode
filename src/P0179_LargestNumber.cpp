//
// Created by yongpu on 2019/10/21 21:01.
//

#include "P0179_LargestNumber.h"

/**
 * 题目：最大数
 * 描述：给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数.
 * 思路：排序，return ab > ba,然后连接.最后判断str[0]是否为0，是则返回0.
 * 备注：注意处理0
 */

int Cmp_P0179(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return ab > ba;
}

string P0179_LargestNumber::largestNumber(vector<int> &nums) {
    vector<int> nums_copy = nums;
    sort(nums_copy.begin(), nums_copy.end(), Cmp_P0179);
    string str;
    int len = nums_copy.size();
    for (int i = 0; i < len; i++) {
        str = str + to_string(nums_copy[i]);
    }
    if (str[0] == '0')
        str = "0";
    return str;
}

int P0179_LargestNumber::test() {
    vector<int> nums = {3, 30, 34, 5, 9};
    string str = largestNumber(nums);
    cout << str << endl;
    return 0;
}
