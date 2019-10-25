//
// Created by yongpu on 2019/10/25 16:07.
//

#include "P0038_CountAndSay.h"

/**
 * 题目：报数
 * 描述：给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项.
 * 思路：当前数的结果基于前一个数的结果，不断递推.如4:1211，1个1,1个2,2个1，得到5:111221.
 * 备注：正常解法就行.
 */

string P0038_CountAndSay::countAndSay(int n) {
    string str;
    if (n < 1 || n > 30) {
        return str;
    }

    str = "1";
    if (n == 1) {
        return str;
    }
    string temp;
    for (int i = 2; i <= n; i++) {
        temp = str;
        str = "";
        int index = 0;
        while (index < temp.length()) {
            char c = temp[index];
            int cnt = 0;
            while (temp[index] == c) {
                cnt++;
                index++;
            }
            str = str + to_string(cnt);
            str.push_back(c);
//            cout << cnt << " " << c << endl;
        }
    }
    return str;
}

int P0038_CountAndSay::test() {
    for (int i = 1; i <= 10; i++) {
        cout << i << ":  " << countAndSay(i) << endl;
    }
    return 0;
}
