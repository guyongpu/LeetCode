//
// Created by yongpu on 2019/10/25 9:11.
//

#include "P0204_CountPrimes.h"

/**
 * 题目：计数质数
 * 描述：统计所有小于非负整数 n 的质数的数量.
 * 思路：使用bool标记数组，然后进行筛法计数.
 * 备注：重要题目.
 */

int P0204_CountPrimes::countPrimes(int n) {
    if(n <= 2){
        return 0;
    }

    vector<bool> numFlag(n, true);
    numFlag[0] = false;
    numFlag[1] = false;
    numFlag[2] = true;

    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (numFlag[i] == true) {
            cnt++;
            for (int j = 2 * i; j < n; j = j + i) {
                numFlag[j] = false;
            }
        }

    }

    return cnt;
}

int P0204_CountPrimes::test() {
    cout << countPrimes(0) << endl;
    cout << countPrimes(1) << endl;
    cout << countPrimes(2) << endl;
    cout << countPrimes(3) << endl;
    cout << countPrimes(10) << endl;
    return 0;
}
