//
// Created by yongpu on 2019/12/4 9:16.
//

#include "P0131_PalindromePartitioning.h"

/**
 * 题目：分割回文串
 * 描述：给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串，返回 s 所有可能的分割方案.
 * 思路：使用DFS深搜计算，注意递归结束条件.
 * 备注：DFS深搜
 */

void DFS(int index, string s, vector<string> temp, vector<vector<string>> &result) {
    if (index == s.length()) {
        result.push_back(temp);
    }
    for (int i = index + 1; i <= s.length(); i++) {
        // 判断回文串
        string str = s.substr(index, i - index);
        string str_rev = str;
        reverse(str_rev.begin(), str_rev.end());

        if (str == str_rev) {
            temp.push_back(str);
            DFS(i, s, temp, result);
            temp.pop_back();
        }
    }
}

vector<vector<string>> P0131_PalindromePartitioning::partition(string s) {
    vector<vector<string>> result;
    vector<string> temp;
    DFS(0, s, temp, result);
    return result;
}

int P0131_PalindromePartitioning::test() {
    vector<vector<string>> result = partition("aab");
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

