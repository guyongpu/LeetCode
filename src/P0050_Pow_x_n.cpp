//
// Created by yongpu on 2019/10/31 17:12.
//

#include "P0050_Pow_x_n.h"

/**
 * 题目：Pow(x,n)
 * 描述：实现 pow(x, n) ，即计算 x 的 n 次幂函数.
 * 思路：递归二分法计算，n为奇数时，half*half;偶数时，half*half*x.
 * 备注：掌握暴力法和递归二分法
 */

double P0050_Pow_x_n::myPow_1(double x, int n) {
    double result = 1;
    long long int n_long = abs((long long int) (n));
    for (long long int i = 0; i < n_long; i++) {
        result = result * x;
    }
    if (n < 0) {
        result = 1 / result;
    }

    return result;
}

/************************************************************/

double P0050_Pow_x_n::myPow_2(double x, int n) {
    long long int n_long = abs((long long int) (n));
    if (n < 0) {
        x = 1 / x;
    }
    double result = fastPow(x, n_long);

    return result;
}

double P0050_Pow_x_n::fastPow(double x, long long int n) {
    if (n == 0) {
        return 1;
    }
    double half = fastPow(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return half * half * x;
    }
}

int P0050_Pow_x_n::test() {
    cout << myPow_2(2.00000, 10) << endl;
    return 0;
}
