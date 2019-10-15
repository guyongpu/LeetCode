//
// Created by yongpu on 2019/10/14 19:41.
//

#include "P0171_ExcelSheetColumnNumber.h"

/**
 * 题目：Excel表列序号
 * 描述：给定一个Excel表格中的列名称，返回其相应的列序号.
 * 思路：26进制转10进制.
 * 备注：此题与169相似
 */

int P0171_ExcelSheetColumnNumber::titleToNumber(string s) {
    int len = s.length();
    if (len == 0)
        return 0;
    int result = 0;
    for (int i = 0; i < len; i++) {
        char c = s.at(len - 1 - i);
        int x = c - 'A' + 1;
        result = result + x * pow(26, i);
    }
    return result;
}

int P0171_ExcelSheetColumnNumber::test() {
    cout << titleToNumber("A") << endl;
    cout << titleToNumber("B") << endl;
    cout << titleToNumber("C") << endl;
    cout << titleToNumber("Z") << endl;
    cout << titleToNumber("AA") << endl;
    cout << titleToNumber("AB") << endl;
    cout << titleToNumber("ZY") << endl;
    return 0;
}
