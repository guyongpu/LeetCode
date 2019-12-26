//
// Created by yongpu on 2019/12/26 16:16.
//

#include "P0139_WordBreak.h"

/**
 * 题目：单词拆分
 * 描述：给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词.
 * 思路：方法1.DFS深搜，但是会超时；方法2.采用动态规划
 * 备注：掌握动态规划思想
 */


void dfs(string str, unordered_set<string> wordSet, int index, bool &result, set<int> lenSet) {
    if (index == str.length() || result) {
        result = true;
        return;
    }

    /*
    for (int i = index; i < str.length(); i++) {
        string temp = str.substr(index, i - index + 1);
        if (wordSet.count(temp) != 0) {
            dfs(str, wordSet, i + 1, result, wordmin, wordmax);
        }
    }*/

    for (auto iter = lenSet.begin(); iter != lenSet.end(); iter++) {
        string temp = str.substr(index, *iter);
        if (wordSet.count(temp) != 0) {
            dfs(str, wordSet, index + *iter, result, lenSet);
        }
    }

}

bool P0139_WordBreak::wordBreak_1(string s, vector<string> &wordDict) {
    unordered_set<string> wordSet;
    wordSet.insert(wordDict.begin(), wordDict.end());

    set<int> lenSet;

    for (int i = 0; i < wordDict.size(); i++) {
        lenSet.insert(wordDict[i].size());
    }


    bool result = false;
    dfs(s, wordSet, 0, result, lenSet);

    return result;
}
/**
 * 动态规划
 * 初始化dp=[False,.....,False]，长度为n+1n+1。n为字符串长度。dp[i]表示s的前i位是否可以用wordDict中的单词表示。
 * 初始化dp[0]=True，空字符可以被表示。
 * 遍历字符串的所有子串，遍历开始索引i，遍历区间[0,n)：
 * 遍历结束索引j，遍历区间[i+1,n+1)：
 * 若dp[i]=Trued且s[i,....,j)在wordlist中：dp[j]=True。
 *  解释：dp[i]=True说明s的前i位可以用wordDict表示，则s[i,⋯,j)出现在wordDict中，说明s的前j位可以表示。
 * 返回dp[n]
 */

bool P0139_WordBreak::wordBreak_2(string s, vector<string> &wordDict) {
    int len = s.size();
    vector<bool> dp(len + 1, false);

    dp[0] = true;

    for (int i = 0; i < len; i++) {
//        cout << i << endl;
        for (int j = i + 1; j < len + 1; j++) {
            string temp = s.substr(i, j - i);
            if (dp[i] == true && find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
                dp[j] = true;
            }
        }
    }


    return dp[len];
}

int P0139_WordBreak::test() {
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << wordBreak_2(s1, wordDict1) << endl;

    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << wordBreak_2(s2, wordDict2) << endl;

    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak_2(s3, wordDict3) << endl;

    string s4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict4 = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
                                "aaaaaaaaaa"};
    cout << wordBreak_2(s4, wordDict4) << endl;

    return 0;
}
