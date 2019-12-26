//
// Created by yongpu on 2019/12/26 16:16.
//

#ifndef LEETCODE_P0139_WORDBREAK_H
#define LEETCODE_P0139_WORDBREAK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

class P0139_WordBreak {
public:
    bool wordBreak_1(string s, vector<string> &wordDict);
    bool wordBreak_2(string s, vector<string> &wordDict);

    int test();
};


#endif //LEETCODE_P0139_WORDBREAK_H
