//
// Created by yongpu on 2019/11/7 9:59.
//

#include "P0067_AddBinary.h"

/**
 * 题目：二进制求和
 * 描述：给定两个二进制字符串，返回他们的和（用二进制表示）.
 * 思路：使用链表合并的思路，while(i>=0 && j >=0),最后处理进位+翻转字符串即可.
 * 备注：链表合并的思想.
 */

string P0067_AddBinary::addBinary(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    if (len_a == 0 || len_b == 0) {
        return len_a == 0 ? b : a;
    }
    string result;
    int i = len_a - 1;
    int j = len_b - 1;
    int carry = 0;
    int ans = 0;
    while (i >= 0 || j >= 0) {
        int numa = 0;
        int numb = 0;
        if (i >= 0) {
            numa = a[i] - '0';
            i--;
        }
        if (j >= 0) {
            numb = b[j] - '0';
            j--;
        }

        int sum = numa + numb + carry;
        ans = sum % 2;
        carry = sum / 2;
        result.push_back(ans+'0');
    }
    if(carry == 1){
        result.push_back('1');
    }
    reverse(result.begin(),result.end());

    return result;
}

int P0067_AddBinary::test() {
    cout << addBinary("0", "0") << endl;
    cout << addBinary("11", "1") << endl;
    cout << addBinary("1010", "1011") << endl;
    cout << addBinary("1", "111111111") << endl;
    return 0;
}
