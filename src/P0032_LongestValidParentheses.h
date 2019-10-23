//
// Created by yongpu on 2019/10/23 10:29.
//

#ifndef LEETCODE_P0032_LONGESTVALIDPARENTHESES_H
#define LEETCODE_P0032_LONGESTVALIDPARENTHESES_H

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class P0032_LongestValidParentheses {
public:
    int longestValidParentheses_1(string s);
    int longestValidParentheses_2(string s);
    int longestValidParentheses_3(string s);
    bool isValid(string str);
    int test();
};


#endif //LEETCODE_P0032_LONGESTVALIDPARENTHESES_H
