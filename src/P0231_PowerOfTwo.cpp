//
// Created by yongpu on 2019/12/27 22:08.
//

#include "P0231_PowerOfTwo.h"

/**
 * 题目：2的幂
 * 描述：给定一个整数，编写一个函数来判断它是否是 2 的幂次方.
 * 思路：方法1.移位，当n=1，则true，否则移位判断；方法2.计算n&(n-1)的结果，如果为0，则true，否则false
 * 备注：掌握方法1和2
 */

bool P0231_PowerOfTwo::isPowerOfTwo(int n) {
    if(n <= 0){
        return false;
    }
    while (1) {
        if (n == 1) {
            return true;
        }

        if ((n & 1) == 0) {
            n = n >> 1;
        } else {
            return false;
        }
    }
    return false;
}

int P0231_PowerOfTwo::test() {
    cout << isPowerOfTwo(16) << endl;
    cout << isPowerOfTwo(218) << endl;
    return 0;
}
