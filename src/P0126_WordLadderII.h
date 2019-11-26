//
// Created by yongpu on 2019/11/25 21:08.
//

#ifndef LEETCODE_P0126_WORDLADDERII_H
#define LEETCODE_P0126_WORDLADDERII_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class P0126_WordLadderII {
public:

    int CheckWord(string currWord, string word);

    void dfs(vector<vector<string>> &result, string currWord, string endWord,
             vector<string> &path, int &MinLen, unordered_map<int, vector<string>> &nextMap,
             unordered_set<string> &visitSet);

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList);

    int ladderLength(string beginWord, string endWord, vector<string> &wordList,
                     unordered_map<int, vector<string> > &nextMap);

    int test();
};


#endif //LEETCODE_P0126_WORDLADDERII_H
