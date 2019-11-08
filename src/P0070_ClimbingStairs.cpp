//
// Created by yongpu on 2019/11/8 11:04.
//

#include "P0070_ClimbingStairs.h"

/**
 * 题目：爬楼梯
 * 描述：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 思路：F(n)=F(n-1)+F(n-2)，方法1：直接循环，temp1记录F(n-1),temp2记录F(n-2)；方法2：采用递归遍历.
 * 备注：递归会超时，采用直接循环.
 */

int P0070_ClimbingStairs::climbStairs_1(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    int temp1 = 1;
    int temp2 = 2;
    int temp_curr = 0;
    for (int i = 3; i <= n; i++) {
        temp_curr = temp1 + temp2;
        swap(temp1, temp2);
        temp2 = temp_curr;
    }
    int result = temp_curr;

    return result;
}

int P0070_ClimbingStairs::climbStairs_2(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return climbStairs_2(n - 1) + climbStairs_2(n - 2);
}

int P0070_ClimbingStairs::test() {
    cout << climbStairs_1(1) << endl;
    cout << climbStairs_1(3) << endl;
    cout << climbStairs_1(4) << endl;
    cout << climbStairs_1(10) << endl;
    cout << climbStairs_1(20) << endl;
    cout << climbStairs_1(30) << endl;
    cout << climbStairs_1(40) << endl;
    return 0;
}
