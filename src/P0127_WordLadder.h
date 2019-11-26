//
// Created by yongpu on 2019/11/26 11:36.
//

#ifndef LEETCODE_P0127_WORDLADDER_H
#define LEETCODE_P0127_WORDLADDER_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class P0127_WordLadder {
public:
    bool CheckWord(string currWord, string word);
    int ladderLength(string beginWord, string endWord, vector<string>& wordList);
    int test();
};


#endif //LEETCODE_P0127_WORDLADDER_H
