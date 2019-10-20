//
// Created by yongpu on 2019/10/16 10:48.
//

#include "P0020_ValidParentheses.h"

/**
 * 题目：有效的括号
 * 描述：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效.
 * 思路：将左括号放入栈中，遇到右括号时出栈，然后进行匹配.
 * 备注：常见题
 */

bool P0020_ValidParentheses::isValid(string s) {
    int len = s.length();
    if (len == 0)
        return true;
    stack<char> sLeft;
    bool result = true;
    for (int i = 0; i < len; i++) {
        if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') //遇到左括号，存入栈中
            sLeft.push(s.at(i));
        else {                                                  //遇到右括号，进行匹配
            if (sLeft.size() == 0) {                            //左括号栈为空，则退出
                result = false;
                break;
            }

            char left = sLeft.top();
            sLeft.pop();
            char right = s.at(i);
            //开始匹配
            if ((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}')) { ;
            } else {
                result = false;
                break;
            }
        }
    }
    if (sLeft.size() != 0) {    //sLeft不为空，则退出
        result = false;
    }

    return result;
}

int P0020_ValidParentheses::test() {
    cout << isValid("") << endl;
    cout << isValid("((((") << endl;
    cout << isValid("(((())))))") << endl;
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("{[]}") << endl;
    return 0;
}
