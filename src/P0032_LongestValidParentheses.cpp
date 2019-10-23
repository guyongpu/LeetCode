//
// Created by yongpu on 2019/10/23 10:29.
//

#include "P0032_LongestValidParentheses.h"

/**
 * 题目：最长有效括号
 * 描述：给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度.
 * 思路：方法1.使用动态规划;方法2.使用暴力求解;方法3.使用栈(保存下标)求解.
 * 备注：重点掌握第2和第3种
 */

// 方法1：动态规划
int P0032_LongestValidParentheses::longestValidParentheses_1(string s) {
    int len = s.length();
    int result = 0;
    vector<int> dp(len, 0);
    for (int i = 1; i < len; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {  // 形如 ()
                if (i >= 2)
                    dp[i] = dp[i - 2] + 2;
                else
                    dp[i] = 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                if ((i - dp[i - 1]) >= 2) {
                    dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                } else
                    dp[i] = dp[i - 1] + 2;
            }
            result = max(result, dp[i]);
        }
    }

    return result;
}

// 方法2：暴力求解
int P0032_LongestValidParentheses::longestValidParentheses_2(string s) {
    int result = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        for (int j = i + 2; j <= len; j = j + 2) {
            if (s[i] == '(' && s[j - 1] == ')' && (j - i) > result && isValid(s.substr(i, j - i))) {
                result = max(result, j - i);
            }
        }
    }
    return result;
}

bool P0032_LongestValidParentheses::isValid(string str) {
    int len = str.length();
    stack<char> open;
    int cnt_open = len / 2;
    int cnt_close = len / 2;
    int index = 0;
    while (index < len) {
        if (str.at(index) == '(') {       // 遇到'('
            cnt_open--;
            open.push('(');
            index++;
        } else {                        // 遇到')'
            cnt_close--;
            if (open.empty()) {         // 栈为空，说明无法匹配
                return false;
            } else {
                open.pop();
                index++;
            }
        }
        if (cnt_close < 0 || cnt_open < 0)
            return false;
    }
    if (open.empty())
        return true;
    return false;
}

// 方法3：使用栈求解
int P0032_LongestValidParentheses::longestValidParentheses_3(string s) {
    stack<int> open;
    int len = s.length();
    int result = 0;
    int start = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(')
            open.push(i);           //保存下标
        else {
            if (open.empty()) {
                start = i + 1;
            } else {
                open.pop();
                if (open.empty()) {
                    result = max(result, i - start + 1);
                } else {
                    result = max(result, i - open.top());
                }
            }
        }
    }
    return result;
}


int P0032_LongestValidParentheses::test() {
    cout << longestValidParentheses_3("(()") << endl;
    cout << longestValidParentheses_1("((())(()(") << endl;
    cout << longestValidParentheses_1("((())(()((()()(()))(()))(((())") << endl;
    cout << longestValidParentheses_1("(()") << endl;
    cout << longestValidParentheses_1("((((()") << endl;
    cout << longestValidParentheses_1("((())(()))))(()") << endl;
    cout << longestValidParentheses_1("(()") << endl;
    cout << longestValidParentheses_1(")()())") << endl;
    return 0;
}
