//
// Created by yongpu on 2019/12/26 20:53.
//

#ifndef LEETCODE_P0140_WORDBREAKII_H
#define LEETCODE_P0140_WORDBREAKII_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class P0140_WordBreakII {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict);
    vector<string> wordBreak_2(string s, vector<string> &wordDict);

    int test();
};


#endif //LEETCODE_P0140_WORDBREAKII_H
