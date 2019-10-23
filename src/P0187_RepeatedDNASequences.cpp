//
// Created by yongpu on 2019/10/21 21:35.
//

#include "P0187_RepeatedDNASequences.h"

/**
 * 题目：重复的DNA序列
 * 描述：编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）
 * 思路：遍历字符串，每10个一组，存入到hashmap中，记录出现的次数.
 * 备注：题目不难.
 */

vector<string> P0187_RepeatedDNASequences::findRepeatedDnaSequences(string s) {
    map<string, int> strMap;
    int len = s.length();
    vector<string> strVec;
    for (int i = 0; i <= len - 10; i++) {
        string str = s.substr(i, 10);

        strMap[str]++;
        if (strMap[str] == 2) {
            strVec.push_back(str);
        }
    }
    return strVec;
}

int P0187_RepeatedDNASequences::test() {
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s2 = "AAAAAAAAAAA";
    vector<string> result = findRepeatedDnaSequences(s2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
