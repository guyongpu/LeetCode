//
// Created by yongpu on 2019/10/24 9:33.
//

#include "P0190_ReverseBits.h"

/**
 * 题目：颠倒二进制位
 * 描述：颠倒给定的 32 位无符号整数的二进制位.
 * 思路：进行32次循环，获取每一位的值，然后进行加法或者位运算，给result的每一位赋值.
 * 备注：掌握方法1(加法计算)和方法2(位运算)
 */

uint32_t P0190_ReverseBits::reverseBits(uint32_t n) {
    uint32_t result = 0;
    uint32_t copy_n;
    for(int i = 0 ; i<32;i++){
        copy_n = n;
        int bit_i = (copy_n >> i) & 1;
//        cout << bit_i;
        result = result + (bit_i << (31 - i));  //方法1.采用加法计算
//        result = result | (bit_i << (31 - i));  //方法2.采用位运算
    }
//    cout<< endl;

    //输出result
    /*
    for(int i = 0 ; i<32;i++){
        copy_n = result;
        int bit_i = (copy_n >> i) & 1;
        cout << bit_i;
    }
    cout<< endl;
     */
    return result;
}

int P0190_ReverseBits::test() {
    cout << reverseBits(43261596) << endl;
    return 0;
}
