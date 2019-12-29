//
// Created by yongpu on 2019/12/29 17:22.
//

#include "P0541_ReverseStringII.h"

/**
 * 题目：反转字符串II
 * 描述：给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转.
 * 思路：计算每K个字符的下标left,right，然后falg为真，则翻转，否则不翻转，falg=!flag.
 * 备注：掌握方法
 */

string P0541_ReverseStringII::reverseStr(string s, int k) {
    int len = s.size();
    int left = 0;
    int right = 0;
    int index = 0;
    bool flag = true;
    while (index < len - 1) {
        left = index;
        right = (index + k - 1) < (len - 1) ? (index + k - 1) : (len - 1);

        index = right + 1;

        if (flag) {
            // 翻转 [left,right]的字符
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        flag = !flag;
    }

    return s;
}

int P0541_ReverseStringII::test() {
    cout << reverseStr("abcdefg", 2) << endl;
    return 0;
}
