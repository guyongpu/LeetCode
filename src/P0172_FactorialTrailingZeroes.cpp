//
// Created by yongpu on 2019/10/14 20:18.
//

#include "P0172_FactorialTrailingZeroes.h"

/**
 * 题目：阶乘后的零
 * 描述：给定一个整数 n，返回 n! 结果尾数中零的数量.
 * 思路：2的个数比5多，所以只要考虑5的个数.用层数的思想，累加每一层5的个数.
 * 备注：比较重要的题.
 * 示例：比如69
 * 第一层：69/5=13，即1*5,2*5,3*5....13*5，共13个
 * 第二层：13/5 =2，即1*5,2*5 ，共2个
 * 无第三层，故共 13+2=15个
 */


int P0172_FactorialTrailingZeroes::trailingZeroes(int n) {
    int reuslt = 0;
    while (n >= 5) {
        reuslt = reuslt + n / 5;
        n = n / 5;
    }
    return reuslt;
}

int P0172_FactorialTrailingZeroes::test() {
    cout << trailingZeroes(69) << endl;
    return 0;
}
