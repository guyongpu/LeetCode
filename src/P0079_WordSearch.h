//
// Created by yongpu on 2019/11/10 17:42.
//

#ifndef LEETCODE_P0079_WORDSEARCH_H
#define LEETCODE_P0079_WORDSEARCH_H

#include <iostream>
#include <vector>

using namespace std;

class P0079_WordSearch {
public:
    bool exist(vector<vector<char>> &board, string word);

    void
    dfs(bool &result, vector<vector<char>> board, vector<vector<bool>> &flag, string word, int row, int col, int x,
        int y,
        int index);

    int test();

};


#endif //LEETCODE_P0079_WORDSEARCH_H
