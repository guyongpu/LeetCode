//
// Created by yongpu on 2019/10/24 10:00.
//

#include "P0191_NumberOf1Bits.h"

/**
 * 题目：位1的个数
 * 描述：编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数.
 * 思路：方法1：进行32次循环，计算每位的情况;2.使用n=n&(n-1)，减少循环次数.
 * 备注：掌握两种方法.
 */

int P0191_NumberOf1Bits::hammingWeight_1(uint32_t n) {
    uint32_t copy_n;
    int result = 0;
    for (int i = 0; i < 32; i++) {
        copy_n = n;
        int bit_i = (copy_n >> i) & 1;
        if (bit_i) {
            result++;
        }
    }
    return result;
}


int P0191_NumberOf1Bits::hammingWeight_2(uint32_t n) {
    uint32_t copy_n;
    int result = 0;
    while(n){
        n = n & (n-1);
        result++;
    }
    return result;
}

int P0191_NumberOf1Bits::test() {
    cout << hammingWeight_2(9) << endl;
    return 0;
}
