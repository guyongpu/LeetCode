//
// Created by yongpu on 2019/10/21 16:09.
//

#ifndef LEETCODE_P0022_GENERATEPARENTHESES_H
#define LEETCODE_P0022_GENERATEPARENTHESES_H

#include <iostream>
#include <vector>

using namespace std;

class P0022_GenerateParentheses {
public:
    vector<string> generateParenthesis(int n);

    void generateParenthesis_sub(vector<string> &result, string str, int open, int close, int n);

    int test();
};


#endif //LEETCODE_P0022_GENERATEPARENTHESES_H
