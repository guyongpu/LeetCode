//
// Created by yongpu on 2019/11/25 21:08.
//

#include "P0126_WordLadderII.h"

void dfs(vector<vector<string>> &result, string currWord, string endWord, vector<bool> visit, vector<string> path,
         string temp_str) {
//    if ()
}


vector<vector<string>> P0126_WordLadderII::findLadders(string beginWord, string endWord, vector<string> &wordList) {
    vector<vector<string>> result;
    if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end() ||
        find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
        return result;
    }

    int len = wordList.size();
    vector<bool> visit(len, true);
    vector<string> path;
    dfs(result, beginWord, endWord, visit, path, beginWord);

    return result;

}

int P0126_WordLadderII::test() {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> result = findLadders("hit", "cog", wordList);
    return 0;
}
