//
// Created by yongpu on 2019/11/8 9:45.
//

#include "P0069_Sqrt_x.h"

/**
 * 题目：x的平方根
 * 描述：实现int sqrt(int x)函数，返回整数部分.
 * 思路：方法1.二分法，注意mid=low+(high-low)/2，否则会溢出；方法2.暴力法
 * 备注：掌握方法2.
 */

// 方法1.二分法
int P0069_Sqrt_x::mySqrt_1(int x) {
    if (x == 0) {
        return 0;
    }
    int low = 1;
    int high = x;
    int result = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid <= x / mid) {
            result = mid;

            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

// 方法2.暴力法
int P0069_Sqrt_x::mySqrt_2(int x) {
    if (x == 0) {
        return 0;
    }
    int end = x / 2;
    int resutl = 0;
    for (int i = 1; i <= end; i++) {
        if (i <= x / i) {
            resutl = i;
        } else {
            break;
        }
    }
    return resutl;
}

int P0069_Sqrt_x::test() {
    cout << mySqrt_1(0) << endl;
    cout << mySqrt_1(1) << endl;
    cout << mySqrt_1(4) << endl;
    cout << mySqrt_1(8) << endl;
    cout << mySqrt_1(9) << endl;
    cout << mySqrt_1(100) << endl;
    cout << mySqrt_1(120) << endl;
    cout << mySqrt_1(121) << endl;
    cout << mySqrt_1(121) << endl;
    cout << mySqrt_1(2147483647) << endl;
    return 0;
}
