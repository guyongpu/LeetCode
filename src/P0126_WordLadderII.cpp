//
// Created by yongpu on 2019/11/25 21:08.
//

#include "P0126_WordLadderII.h"

/**
 * 题目：单词接龙II
 * 描述：给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列.
 * 思路：先计算出最短路径，在根据最短路径计算路径，即BFS+DFS，合理运用map和set
 * 备注：BFS+DFS
 */

int P0126_WordLadderII::CheckWord(string currWord, string word) {
    int len = word.size();
    int cnt = 0;
    for (int j = 0; j < len; j++) {
        if (currWord[j] != word[j]) {
            cnt++;
            if (cnt > 1) {
                return false;
            }
        }
    }
    return true;
}

void P0126_WordLadderII::dfs(vector<vector<string>> &result, string currWord, string endWord,
                             vector<string> &path, int &MinLen, unordered_map<int, vector<string>> &nextMap,
                             unordered_set<string> &visitSet) {
    if (currWord == endWord) {
        result.push_back(path);
    } else {
        if (path.size() >= MinLen) {
            return;
        }
        int step = path.size() - 1;
        vector<string> nextVec = nextMap[step];
        for (int i = 0; i < nextVec.size(); i++) {
            if (visitSet.find(nextVec[i]) == visitSet.end() && CheckWord(currWord, nextVec[i])) {
                path.push_back(nextVec[i]);
                visitSet.insert(nextVec[i]);
                dfs(result, nextVec[i], endWord, path, MinLen, nextMap, visitSet);
                path.pop_back();
                visitSet.erase(nextVec[i]);
            }
        }
    }
}

vector<vector<string>> P0126_WordLadderII::findLadders(string beginWord, string endWord, vector<string> &wordList) {
    vector<vector<string>> result;
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
        return result;
    }
    unordered_map<int, vector<string> > nextMap;
    int MinLen = ladderLength(beginWord, endWord, wordList, nextMap);
    cout << "MinLen = " << MinLen << endl;
    vector<string> path = {beginWord};
    unordered_set<string> visitSet;
    dfs(result, beginWord, endWord, path, MinLen, nextMap, visitSet);

    return result;
}


int P0126_WordLadderII::ladderLength(string beginWord, string endWord, vector<string> &wordList,
                                     unordered_map<int, vector<string>> &nextMap) {
    auto iter = find(wordList.begin(), wordList.end(), endWord);
    if (iter == wordList.end()) {
        return 0;
    }

    queue<string> que_begin({beginWord});
    int len = wordList.size();

    vector<bool> visit(len, true);


    int step = 0;

    vector<int> indexVec;
    for (int i = 0; i < len; i++) {
        indexVec.push_back(i);
    }
    while (que_begin.size()) {
        // 对 que_begin 队列BFS遍历
        int len_begin = que_begin.size();
        if (len_begin) {
            step++;
        }
        vector<string> nextVec;
        for (int i = 0; i < len_begin; i++) {
            string temp_begin = que_begin.front();
            que_begin.pop();

            if (temp_begin == endWord) {
                return step;
            }

            int lenIndex = indexVec.size();
            vector<int> temp;
            for (int j = 0; j < lenIndex; j++) {
                int n = indexVec[j];
                if (visit[n] && CheckWord(temp_begin, wordList[n])) {
                    que_begin.push(wordList[n]);
                    nextVec.push_back(wordList[n]);
                    visit[n] = false;
                } else {
                    temp.push_back(n);
                }
            }
            indexVec = temp;

            nextMap[step - 1] = nextVec;
        }
    }
    return 0;
}

int P0126_WordLadderII::test() {
    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> result = findLadders("hit", "cog", wordList1);
    /*
    vector<string> wordList =
            {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le",
             "av",
             "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya",
             "cr",
             "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo",
             "as",
             "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha",
             "hz",
             "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la",
             "st",
             "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni",
             "mr",
             "pa", "he", "lr", "sq", "ye"};
    vector<vector<string>> result = findLadders("qa", "sq", wordList);
    */
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/****************************************************************
int CheckWord(string currWord, string word) {
        int len = word.size();
        int cnt = 0;
        for (int j = 0; j < len; j++) {
            if (currWord[j] != word[j]) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    void dfs(vector<vector<string>> &result, string currWord, string endWord, vector<string> &wordList, vector<bool> &visit,
             vector<string> &path, int &MinLen) {
        if (currWord == endWord) {
            result.push_back(path);
        } else {
            if (path.size() >= MinLen) {
                return;
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (visit[i] && CheckWord(currWord, wordList[i])) {
                    path.push_back(wordList[i]);
                    visit[i] = false;
                    dfs(result, wordList[i], endWord, wordList, visit, path, MinLen);
                    visit[i] = true;
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> result;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return result;
        }

        int MinLen = ladderLength(beginWord, endWord, wordList);
        int len = wordList.size();
        vector<bool> visit(len, true);
        vector<string> path = {beginWord};
        dfs(result, beginWord, endWord, wordList, visit, path, MinLen);

        return result;
    }


    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        auto iter = find(wordList.begin(), wordList.end(), endWord);
        if (iter == wordList.end()) {
            return 0;
        }
        queue<string> que_begin({beginWord});
        queue<string> que_end({endWord});
        int len = wordList.size();

        vector<int> visit(len, 0);
        visit[iter - wordList.begin()] = 2;

        iter = find(wordList.begin(), wordList.end(), beginWord);
        if (iter != wordList.end()) {
            visit[iter - wordList.begin()] = 1;
        }

        int step = 1;
        while (que_begin.size() && que_end.size()) {
            // 对 que_begin 队列BFS遍历
            int len_begin = que_begin.size();
            if (len_begin) {
                step++;
            }
            for (int i = 0; i < len_begin; i++) {
                string temp_begin = que_begin.front();
                que_begin.pop();
                for (int j = 0; j < len; j++) {
                    if (visit[j] != 1 && CheckWord(temp_begin, wordList[j])) {
                        if (visit[j] == 0) {
                            que_begin.push(wordList[j]);
                            visit[j] = 1;
                        } else {
                            return step;
                        }
                    }
                }
            }

            // 对 que_end 队列BFS遍历
            int len_end = que_end.size();
            if (len_end) {
                step++;
            }
            for (int i = 0; i < len_end; i++) {
                string temp_end = que_end.front();
                que_end.pop();
                for (int j = 0; j < len; j++) {
                    if (visit[j] != 2 && CheckWord(temp_end, wordList[j])) {
                        if (visit[j] == 0) {
                            que_end.push(wordList[j]);
                            visit[j] = 2;
                        } else {
                            return step;
                        }
                    }
                }
            }
        }
        return 0;
    }
    ***************************************************************/