//
// Created by yongpu on 2019/10/20 16:30.
//

#include "P0029_DivideTwoIntegers.h"

/**
 * 题目：两数相除
 * 描述：给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 思路：法1：不断减除数，但会超时；2.位移代替除法，（1）处理好被除数=INT_MIN，单独做一次减法；（2）不能直接写result_1+result_2>INT_MAX，会溢出
 * 备注：掌握用位移代替除法，以及result>INT_MAX可能会溢出
 */


int P0029_DivideTwoIntegers::divide_2(int dividend, int divisor) {
    if (dividend == 0 || divisor == 0)
        return 0;
    bool sign = false;
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
        sign = true;
    } else {
        sign = false;
    }

    int result = 0;

    //全部转化为负数
    if (dividend > 0) {
        dividend = -dividend;
    }
    if (divisor > 0) {
        divisor = -divisor;
    }

    //不断减除数
    //cout << dividend << " " << divisor << endl;
    while (dividend <= divisor) {
        dividend = dividend - divisor;


        if (result == INT_MAX) {
            if (sign == true) {
                result = INT_MAX;
                return result;
            } else {
                result = INT_MIN;
                return result;
            }
        }
        result++;
    }

    if (sign == false) {
        result = -result;
    }
    return result;
}


int P0029_DivideTwoIntegers::divide_1(int dividend, int divisor) {
    // 特判,处理后divisor在[-2^31-1,2^31-1]之间

    if (divisor == 0)                           // 当divisor=0，则返回0，非法情况
        return 0;
    if (dividend == divisor)                    // 当dividend = divisor ，返回1
        return 1;
    if (divisor == 1)                           // 当divisor=1 ,则返回 dividend
        return dividend;
    if (dividend == INT_MIN && divisor == -1)   // 当divisor=INT_MIN ,divisor=-1，则返回INT_MAX
        return INT_MAX;

    if (divisor == INT_MIN) {                   // 当divisor=INT_MIN，若dividend=INT_MIN，则返回1，否则返回0
        if (dividend == INT_MIN)
            return 1;
        else
            return 0;
    }

    // 符号位
    bool sign = false;
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
        sign = true;
    }

    // 当 dividend 为INT_MIN时，不能直接使用abs函数，因此先使用一次减法，使 dividend变小，然后再使用abs函数
    int result_1 = 0;   //结果1
    if (dividend == INT_MIN) {
        int divisor_copy = divisor;
        if (divisor > 0)                //dividend负数，divisor正数
            divisor_copy = -divisor;
        dividend = dividend - divisor_copy;
        result_1++;
    }

    // 此时dividend，divisor 都不会溢出,且接下来的计算结果不会溢出
    dividend = abs(dividend);
    divisor = abs(divisor);
    int result_2 = 0;   //结果2

    for (int i = 31; i >= 0; i--) {
        if ((dividend >> i) >= divisor) {
            int temp = 1 << i;
            result_2 = result_2 + temp;
            int val = divisor << i;
            dividend = dividend - val;
        }
    }

    if (sign == true) { // 正数
        if (INT_MAX - result_2 < result_1)  //这里不能写成 result_1 + result_2 > INT_MAX，这样会溢出
            return INT_MAX;
        int result = result_1 + result_2;
        return result;
    } else {
        int result = -result_1 - result_2;
        return result;
    }
}


int P0029_DivideTwoIntegers::test() {
    cout << divide_1(10, 3) << endl;
    cout << divide_1(6, 3) << endl;
    cout << divide_1(-48, 48) << endl;
    cout << divide_1(-48, 4) << endl;
    cout << divide_1(-48, 1) << endl;
    cout << divide_1(-48, 49) << endl;
    cout << divide_1(-48, 5) << endl;
    cout << divide_1(-48, -48) << endl;
    cout << divide_1(48, -4) << endl;
    cout << divide_1(-48, -1) << endl;
    cout << divide_1(-48, -49) << endl;
    cout << divide_1(48, 12) << endl;
    cout << divide_1(-2147483648, -1) << endl;
    cout << divide_1(-2147483648, 2) << endl;
    cout << divide_1(-2147483648, 1) << endl;
    cout << divide_1(-2147483647, 1) << endl;
    cout << divide_1(2147483647, 1) << endl;
    cout << divide_1(2147483646, 1) << endl;
    cout << divide_1(-2147483645, 1) << endl;
    return 0;
}
