//
// Created by yongpu on 2019/10/25 8:31.
//

#include "P0202_HappyNumber.h"

/**
 * 题目：快乐数
 * 描述：编写一个算法来判断一个数是不是“快乐数”，即讲各个位上的平方累加，最终和为1.
 * 思路：如果累加和重复出现，则说明不是快乐数，直接用hashmap判断是否重复即可.
 * 备注：hashmap判断是否重复
 *
 * @param n
 * @return
 */

bool P0202_HappyNumber::isHappy(int n) {
    map<int, int> record;
    while (n != 1) {
        if (record[n] == 1) { //重复出现
            return false;
        }
        record[n] = 1;
        int sum = 0;
        while (n) {
            int val = n % 10;
            n = n / 10;
            sum = sum + val * val;
        }
        n = sum;
    }
    return true;
}

int P0202_HappyNumber::test() {
    cout << isHappy(19) << endl;
    cout << isHappy(2) << endl;
    return 0;
}
