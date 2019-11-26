//
// Created by yongpu on 2019/11/26 11:36.
//

#include "P0127_WordLadder.h"

/**
 * 题目：单词接龙
 * 描述：给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度.
 * 思路：使用BFS计算出最短转换序列
 * 备注：BFS/双向BFS
 */

bool P0127_WordLadder::CheckWord(string currWord, string word) {
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


int P0127_WordLadder::ladderLength(string beginWord, string endWord, vector<string> &wordList) {
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

int P0127_WordLadder::test() {
    vector<string> wordList1 = {"a", "b", "c"};
    cout << ladderLength("a", "c", wordList1) << endl;
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << ladderLength("hit", "cog", wordList2) << endl;

    vector<string> wordList3 =
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
    cout << ladderLength("qa", "sq", wordList3) << endl;
    return 0;
}
