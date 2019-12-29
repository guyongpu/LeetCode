//
// Created by yongpu on 2019/12/29 13:13.
//

#include "P0344_ReverseString.h"

/**
 * 题目：反转字符串
 * 描述：编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出.
 * 思路：使用双指针法，left和right指针相互交换.
 * 备注：掌握即可
 */

void P0344_ReverseString::reverseString(vector<char> &s) {
    int num = s.size();
    int left = 0;
    int right = num - 1;
    char temp;
    while (left < right) {
        temp = s[left];
        s[right] = s[left];
        s[left] = temp;
        left++;
        right--;
    }
}

int P0344_ReverseString::test() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    return 0;
}
