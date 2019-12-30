//
// Created by yongpu on 2019/12/30 21:02.
//

#include "P0263_UglyNumber.h"

/**
 * 题目：丑数
 * 描述：编写一个程序判断给定的数是否为丑数。丑数就是只包含质因数 2, 3, 5 的正整数。
 * 思路：不断除以2/3/5，如果不能整除，则false，为1，则返回true.
 * 备注：掌握方法.
 */

bool P0263_UglyNumber::isUgly(int num) {
    if(num <= 0){
        return false;
    }
    while (num != 1) {
        if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
            if (num % 2 == 0) {
                num = num / 2;
            } else if (num % 3 == 0) {
                num = num / 3;
            } else {
                num = num / 5;
            }
        } else {
            return false;
        }
    }
    return true;
}

int P0263_UglyNumber::test() {
    cout << isUgly(1) << endl;
    cout << isUgly(6) << endl;
    cout << isUgly(8) << endl;
    cout << isUgly(14) << endl;
    return 0;
}
