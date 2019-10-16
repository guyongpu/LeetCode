//
// Created by yongpu on 2019/10/15 12:30.
//

#include "P0008_StringToInteger_atoi.h"

/**
 * 题目：字符串转换整数(atoi)
 * 描述：请你来实现一个 atoi 函数，使其能将字符串转换成整数.
 * 思路：先找到开始字符，然后逐个转换，注意溢出的判断方法.
 * 备注：记住溢出判断方法
 */

int P0008_StringToInteger_atoi::myAtoi(string str) {
    if (str.length() == 0)
        return 0;

    int result = 0;
    int len = str.length();
    int index = 0;
    int flag = false;       //符号位，正负数标记

    //寻找数字起始位置为index
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ')
            continue;
        else if ('0' <= str[i] && str[i] <= '9') {
            index = i;
            flag = true;
            break;
        } else if (str[i] == '+') {
            index = i + 1;
            flag = true;
            break;
        } else if (str[i] == '-') {
            index = i + 1;
            flag = false;
            break;
        } else {
            break;
        }
    }

    //判断str[index]是否为数字，不是则直接退出计算
    if (index >= len || !('0' <= str[index] && str[index] <= '9')) {
        result = 0;
    } else {    //开始转换
        for (int i = index; i < len; i++) {
            if ('0' <= str[i] && str[i] <= '9') {
                int num = str[i] - '0';
                if (flag == true) { //正数
                    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && num > 7)) {     //正数溢出判断
                        result = INT_MAX;
                        break;
                    }
                    result = result * 10 + num;
                } else {            //负数
                    num = -num;
                    if (result < INT_MIN / 10 || (result == INT_MIN / 10 && num < -8)) {    //负数溢出判断
                        result = INT_MIN;
                        break;
                    }
                    result = result * 10 + num;
                }
            } else {
                break;
            }
        }
    }

    return result;
}

int P0008_StringToInteger_atoi::test() {
    cout << myAtoi("42") << endl;
    cout << myAtoi("0") << endl;
    cout << myAtoi("-180") << endl;
    cout << myAtoi("-180czx") << endl;
    cout << myAtoi("   -180") << endl;
    cout << myAtoi("   18er0") << endl;
    cout << myAtoi("words and 987") << endl;
    cout << myAtoi("++1") << endl;
    cout << myAtoi("-+1") << endl;
    cout << myAtoi("-r") << endl;
    cout << myAtoi("91283472332") << endl;
    cout << myAtoi("-91283472332") << endl;
    cout << myAtoi("-2147483649") << endl;
    return 0;
}
