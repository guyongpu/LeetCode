//
// Created by yongpu on 2019/10/14 14:50.
//

#include "P0017_LetterCombinationsOfAPhoneNumber.h"

/**
 * 题目：电话号码的字母组合
 * 描述：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合.
 * 思路：使用递归方法，每遇到一个字符，则拼接该字符的所有情况，然后递归下一个字符.
 * 备注：注意复习.
 */

vector<string> P0017_LetterCombinationsOfAPhoneNumber::letterCombinations(string digits) {
    //字符映射表
    vector<vector<string >> charTable = {
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
    };
    vector<string> result;
    string temp;
    letterCombinations_sub(result, digits, temp, charTable, 0);
    return result;
}

void P0017_LetterCombinationsOfAPhoneNumber::letterCombinations_sub(vector<string> &result, string digits, string temp,
                                                                    vector<vector<string>> charTable, int index) {
    if (index < digits.length()) {              //index小于length
        if (index == digits.length() - 1) {     // 最后一个元素
            //拼接所有可能的结果
            for (int j = 0; j < charTable[digits[index] - '0' - 2].size(); j++) {
                string str = temp + charTable[digits[index] - '0' - 2][j];
                result.push_back(str);          //将结果存入result中
            }
        } else {                                //不是最后一个元素
            //拼接所有digits[i]的字符，递归下一个
            for (int k = 0; k < charTable[digits[index] - '0' - 2].size(); k++) {
                letterCombinations_sub(result, digits, temp + charTable[digits[index] - '0' - 2][k], charTable,
                                       index + 1);
            }
        }
    }
}


int P0017_LetterCombinationsOfAPhoneNumber::test() {
    vector<string> result = letterCombinations("234");
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

