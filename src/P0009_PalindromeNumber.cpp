//
// Created by yongpu on 2019/10/15 14:35.
//

#include "P0009_PalindromeNumber.h"

/**
 * 题目：回文数
 * 描述:判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数.
 * 思路：法1：转化为字符串，然后判断是否回文;法2:计算一半数字,比较halfNum_l和halfNum_r.
 * 备注：掌握两种方法.
 */

//方法1：转化为字符串，然后判断是否回文
bool P0009_PalindromeNumber::isPalindrome_1(int x) {
    if (x < 0)
        return false;
    string str = to_string(x);
    int len = str.length();
    int left = 0;
    int right = len - 1;

    bool result = true;
    while (left <= right) {
        if (str[left] == str[right]) {
            left++;
            right--;
        } else {
            result = false;
            break;
        }
    }
    return result;
}

//方法2：计算一半数字,比较halfNum_l和halfNum_r
bool P0009_PalindromeNumber::isPalindrome_2(int x) {
    if (x < 0)
        return false;
    //获取数字位数
    int bitNum = 0;
    int copy_x = x;
    while (copy_x) {
        bitNum++;
        copy_x = copy_x / 10;
    }
    //只有一位，直接返回
    if (bitNum == 1)
        return true;

    int halfNum_l = 0;    //左半边，例如13431为13
    int halfNum_r = 0;    //右半边，例如13431转化为13

    //计算 halfNum_l
    if (bitNum % 2 == 1) {
        halfNum_l = x / pow(10, (bitNum + 1) / 2);
    } else {
        halfNum_l = x / pow(10, bitNum / 2);
    }

    //计算 halfNum_r
    copy_x = x;
    for (int i = 0; i < bitNum / 2; i++) {
        halfNum_r = halfNum_r * 10 + copy_x % 10;
        copy_x = copy_x / 10;
    }

//    cout << halfNum_l << endl;
//    cout << halfNum_r << endl;

    // 比较 halfNum_l 和 halfNum_r
    bool result = true;
    if (halfNum_l == halfNum_r)
        result = true;
    else
        result = false;
    return result;
}

int P0009_PalindromeNumber::test() {
    cout << isPalindrome_2(112211) << endl;
    cout << isPalindrome_2(0) << endl;
    cout << isPalindrome_2(6) << endl;
    cout << isPalindrome_2(-121) << endl;
    cout << isPalindrome_2(13431) << endl;
    cout << isPalindrome_2(134431) << endl;
    return 0;
}
