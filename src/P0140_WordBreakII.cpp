//
// Created by yongpu on 2019/12/26 20:53.
//

#include "P0140_WordBreakII.h"

/**
 * 题目：单词拆分II
 * 描述：给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子.
 * 思路：方法1.使用DFS计算，超时；方法2.使用记忆化搜索方式，构造hashmap进行剪枝.
 * 备注：掌握两种方法.
 */

void dfs(string str, unordered_set<string> wordSet, int index, vector<string> temp_result, vector<string> &result,
         set<int> lenSet) {
    if (index == str.length()) {
        string str_result = temp_result[0];
        for (int i = 1; i < temp_result.size(); i++) {
            str_result = str_result + " " + temp_result[i];
        }
        result.push_back(str_result);
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
        if (index + *iter > str.length()) {
            break;
        }
        string temp = str.substr(index, *iter);
        if (wordSet.count(temp) != 0) {
            temp_result.push_back(temp);
            dfs(str, wordSet, index + *iter, temp_result, result, lenSet);
            temp_result.pop_back();
        }
    }
}

vector<string> P0140_WordBreakII::wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordSet;
    wordSet.insert(wordDict.begin(), wordDict.end());

    set<int> lenSet;

    for (int i = 0; i < wordDict.size(); i++) {
        lenSet.insert(wordDict[i].size());
    }

    vector<string> temp_result;
    vector<string> result;
    dfs(s, wordSet, 0, temp_result, result, lenSet);

    return result;
}

/*****************************************************************************************/
// 方法2
/*
 * 为了避免这种情况，我们使用记忆化的方法，我们使用一个 key:value 这样的哈希表来进行优化。在哈希表中，key是当前考虑字符串的开始下标，
 * value包含了所有从头开始的所有可行句子。下次我们遇到相同位置开始的调用时，我们可以直接从哈希表里返回结果，而不需要重新计算结果.
 * 通过记忆化的方法，许多冗余的子问题都可以被省去，回溯树得到了剪枝，所以极大程度降低了时间复杂度
 */
vector<string> wordBreak_sub(string s, unordered_set<string> &t, unordered_map<int, vector<string>> &m, int index) {
    if (m.count(index)) {
        return m[index];
    }
    vector<string> ret;
    if (index == s.size()) {
        ret.emplace_back("");
    } else
        for (int i = index + 1; i <= s.size(); ++i) {

            if (t.count(s.substr(index, i - index))) {
                vector<string> tmp = wordBreak_sub(s, t, m, i);
                for (auto &j : tmp) {
                    ret.push_back(s.substr(index, i - index) + (j.empty() ? "" : " ") + j);
                }
            }
        }
    m[index] = ret;
    return ret;
}

// 记忆化搜索
vector<string> P0140_WordBreakII::wordBreak_2(string s, vector<string> &wordDict) {
    unordered_set<string> t(wordDict.begin(), wordDict.end());
    unordered_map<int, vector<string>> m;
    return wordBreak_sub(s, t, m, 0);
}

/*****************************************************************************************/

int P0140_WordBreakII::test() {
    vector<string> result;

    string s0 = "catsanddog";
    vector<string> wordDict0 = {"cat", "cats", "and", "sand", "dog"};
    result = wordBreak(s0, wordDict0);

    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    result = wordBreak(s1, wordDict1);

    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    result = wordBreak(s2, wordDict2);

    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    result = wordBreak(s3, wordDict3);

    string s4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict4 = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
                                "aaaaaaaaaa"};
    result = wordBreak(s4, wordDict4);
    return 0;
}
