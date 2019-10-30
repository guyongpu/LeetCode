//
// Created by yongpu on 2019/10/26 16:12.
//

/**
 * 题目：字符串相乘
 * 描述：给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式.
 * 思路：num1中每一位乘以nums，然后将结果进行累加，实现一个字符串相加的函数即可.
 * 备注：需要仔细些.
 */

#include "P0043_MultiplyStrings.h"

string addstr(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len1 = num1.length();
    int len2 = num2.length();
    int lenMax = max(len1, len2);

    //补0，使num1和num2长度一样
    for (int i = 0; i < lenMax - len1; i++) {
        num1.push_back('0');
    }
    for (int i = 0; i < lenMax - len2; i++) {
        num2.push_back('0');
    }

    //相加,长度都为lenMax
    int carry = 0;
    string ans;
    for (int i = 0; i < lenMax; i++) {
        int a = num1[i] - '0';
        int b = num2[i] - '0';
        int sum = a + b + carry;
        ans.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry > 0) {
        ans.push_back(carry + '0');
    }

    //翻转得到结果
    reverse(ans.begin(), ans.end());
    return ans;
}

string P0043_MultiplyStrings::multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
        return string("0");

    //用短*长，计算更快
    if (num1.length() > num2.length()) {
        swap(num1, num2);
    }
    int len1 = num1.length();
    int len2 = num2.length();

    vector<string> record(10, "-1");    //record用于避免重复计算
    record[0] = "0";
    record[1] = num2;

    string result;
    int cnt = 0;
    for (int i = len1 - 1; i >= 0; i--) {
        cnt++;
        int a = num1[i] - '0';
        string tempSum;

        // 计算 a * num2 = tempSum
        if (record[a] == "-1") {    //如果record中没有保存，则计算
            int carry = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int ans = a * b + carry;

                tempSum.push_back((ans % 10) + '0');
                carry = ans / 10;
            }
            if (carry > 0) {
                tempSum.push_back(carry + '0');
            }
            reverse(tempSum.begin(), tempSum.end());

            // 将tempSum存入到record中，下次无需重复计算
            record[a] = tempSum;
        } else {
            tempSum = record[a];    //直接从record[a]中获取结果
        }

        //需要补0，相当于*10
        for (int k = 1; k < cnt; k++) {
            tempSum.push_back('0');
        }

        // result = result + tempSum
        result = addstr(result, tempSum);
    }

    return result;
}

int P0043_MultiplyStrings::test() {
    cout << multiply("0", "0") << endl;
    cout << multiply("123", "456") << endl;             //56088
    cout << multiply("988", "12") << endl;              //11856
    cout << multiply("8954666", "48974651") << endl;    //438551642171566
    return 0;
}
