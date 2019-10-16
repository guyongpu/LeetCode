//
// Created by yongpu on 2019/10/15 9:55.
//

#include "P0006_ZigZagConversion.h"

/**
 * 题目：Z字形变换
 * 描述：将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列.
 * 思路：floor从1->numRows,然后numRows->1，遍历字符串，分别存入到每层的字符串中，最后拼接起来.
 * 备注：要仔细些.
 */

string P0006_ZigZagConversion::convert(string s, int numRows) {
    if(numRows == 1)
        return s;

    vector<string> vecstr(numRows + 1);
    int len = s.length();

    int floor = 1;
    bool flag = true;
    for (int i = 0; i < len; i++) {
        char c = s.at(i);
        vecstr[floor].push_back(c);


        if (flag == true) {
            if (floor < numRows) {
                floor++;
                continue;
            }
        } else {
            if (floor > 1) {
                floor--;
                continue;
            }
        }
        if (floor == numRows) {
            flag = false;
            floor --;
            continue;
        }
        if (floor == 1) {
            flag = true;
            floor ++;
            continue;
        }
    }
    string result;
    for(int i = 1 ;i<= numRows;i++){
        result = result + vecstr[i];
    }
    return result;
}

int P0006_ZigZagConversion::test() {
    cout << convert("LEETCODEISHIRING", 3) << endl;
    cout << convert("LEETCODEISHIRING", 4) << endl;
    return 0;
}
