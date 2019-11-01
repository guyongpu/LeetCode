//
// Created by yongpu on 2019/11/1 11:36.
//

#include "P0211_AddAndSearchWord_DataStructureDesign.h"

/**
 * 题目：添加与搜索单词-数据结构设计
 * 描述：设计一个支持addWord和search两种操作的数据结构，可以搜索文字或正则表达式字符串.
 * 思路：使用map<int,vector<string>>，长度为key，将长度相同的字符串放在一个vector中，然后查找.
 * 备注：长度hashmap字典或者前缀树都可以
 */

void P0211_AddAndSearchWord_DataStructureDesign::addWord(string word) {
    int len = word.length();
    mapDict[len].push_back(word);
}

bool P0211_AddAndSearchWord_DataStructureDesign::search(string word) {
    int len = word.length();
    vector<string> strvec = mapDict[len];
    int num = strvec.size();
    bool result = false;
    for (int i = 0; i < num; i++) {
        result = true;
        string cmpstr = strvec[i];
        string wordstr = word;
        for (int j = 0; j < len; j++) {
            if (wordstr[j] == cmpstr[j] || wordstr[j] == '.') {
                continue;
            } else {
                result = false;
                break;
            }
        }
        if (result == true) {
            break;
        }
    }
    return result;
}

int P0211_AddAndSearchWord_DataStructureDesign::test() {
    addWord("bad");
    addWord("dad");
    addWord("mad");
    addWord("a");
    addWord("b");
    addWord("c");
    addWord("word");
    addWord("park");
    addWord("good");
    cout << search("pad") << endl;
    cout << search("bad") << endl;
    cout << search(".ad") << endl;
    cout << search("b..") << endl;
    cout << search("b.aa.") << endl;
    return 0;
}
