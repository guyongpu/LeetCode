//
// Created by yongpu on 2019/10/24 16:19.
//

#include "P0201_BitwiseANDOfNumbersRange.h"

/**
 * 题目：数字范围按位与
 * 描述：给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）.
 * 思路：方法1.从高位开始，第i位相同，则累加，不同则停止;方法2.不断右移，直到m=n，然后再在后面补0.
 * 备注：掌握方法1和方法3
 */

// 方法1.从高位开始累加，直到m和n的第i位不相同，则停止
int P0201_BitwiseANDOfNumbersRange::rangeBitwiseAnd_1(int m, int n) {
    int result = 0;

    for (int i = 30; i >= 0; i--) {
        int num = 1 << i;
        if (n >= num && m < num) {  //当第i位不相同，则停止
            break;
        } else if (n >= num && m >= num) {  //相同，则累加
            n = n - num;
            m = m - num;
            result = result + num;
        }
    }

    return result;
}

// 方法2.简单版，方法1最初的版本
int P0201_BitwiseANDOfNumbersRange::rangeBitwiseAnd_2(int m, int n) {
    int result = 0;

    bool firstSign = false;
    for (int i = 30; i >= 0; i--) {
        int num = 1 << i;
        if (firstSign == false) {
            if (n >= num && m < num) {
                break;
            } else if (n >= num && m >= num) {
                n = n - num;
                m = m - num;
                result = result + num;
                firstSign = true;
            }
        } else {
            if (n >= num && m < num) {
                break;
            } else if (n >= num && m >= num) {
                n = n - num;
                m = m - num;
                result = result + num;
            }
        }
    }

    return result;
}

// 方法3.寻找[m,n]范围内二进制数高位（左边）没有变化的数，后面补上0即为所求的结果
int P0201_BitwiseANDOfNumbersRange::rangeBitwiseAnd_3(int m, int n) {
    int cnt = 0;
    while (n != m) {
        n = n >> 1;
        m = m >> 1;
        cnt++;
    }
    int result = n << cnt;

    return result;
}


int P0201_BitwiseANDOfNumbersRange::test() {
    cout << rangeBitwiseAnd_3(5, 7) << endl;  //4
    cout << rangeBitwiseAnd_3(1, 2) << endl;
    return 0;
}

