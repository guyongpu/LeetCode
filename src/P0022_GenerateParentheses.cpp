//
// Created by yongpu on 2019/10/21 16:09.
//

#include "P0022_GenerateParentheses.h"

/**
 * 题目：括号生成
 * 描述：给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合.
 * 思路：递归，当open数量小于n的数量，则加一个open，close数量小于open的数量，则加一个close.
 * 备注：掌握递归方法.
 */

vector<string> P0022_GenerateParentheses::generateParenthesis(int n) {
    vector<string> result;
    string str;
    generateParenthesis_sub(result, str, 0, 0, n);
    return result;
}

void
P0022_GenerateParentheses::generateParenthesis_sub(vector<string> &result, string str, int open, int close, int n) {
    if (str.length() == n * 2) {
        result.push_back(str);
        return;
    }
    if (open < n) {         // open数量小于n的数量，则加一个open
        generateParenthesis_sub(result, str + "(", open + 1, close, n);
    }
    if (close < open) {     // close数量小于open的数量，则加一个close
        generateParenthesis_sub(result, str + ")", open, close + 1, n);
    }
}

int P0022_GenerateParentheses::test() {
    vector<string> result = generateParenthesis(1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
