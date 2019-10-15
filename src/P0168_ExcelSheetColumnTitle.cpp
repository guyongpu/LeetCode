//
// Created by yongpu on 2019/10/14 16:02.
//

#include "P0168_ExcelSheetColumnTitle.h"

/**
 * 题目：Excel表列名称
 * 描述：给定一个正整数，返回它在 Excel 表中相对应的列名称.
 * 思路：26进制转换，难点在于余数=0时要向商借1位，否则会出错.
 * 备注：记住难点的处理方法.
 */

string P0168_ExcelSheetColumnTitle::convertToTitle(int n) {
    string result;
    if (n <= 0)
        return string("");;
    int k = 26;

    while (n) {
        int x = n % k;
        if (x == 0) {                           //x=0，看做26,，并向商借一位
            result.push_back('Z');
            n = n / k - 1;                      //难点，要向商借一位
        } else {
            result.push_back('A' + x - 1);
            n = n / k;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int P0168_ExcelSheetColumnTitle::test() {
    cout << convertToTitle(1) << endl;
    cout << convertToTitle(26) << endl;
    cout << convertToTitle(27) << endl;
    cout << convertToTitle(28) << endl;
    cout << convertToTitle(676) << endl;
    cout << convertToTitle(701) << endl;
    cout << convertToTitle(1710) << endl;
    return 0;
}


