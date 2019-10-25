//
// Created by yongpu on 2019/10/25 9:47.
//

#include "P0205_IsomorphicStrings.h"

/**
 * 题目：同构字符串
 * 描述：给定两个字符串 s 和 t，判断它们是否是同构的，如add与egg.
 * 思路：方法1.构建sTOt和tTOs的映射，检测是否存在一对多情况；方法2.计算字符首次出现的下标，如序列相等，则满足.
 * 备注：掌握方法1和方法2
 */

/**
 * 方法1.构建sTOt和tTOs的映射
 * 检测是否存在一对多的情况，若sTOt和tTOs都满足，则返回true.
 */
bool P0205_IsomorphicStrings::isIsomorphic_1(string s, string t) {
    int len_s = s.length();
    int len_t = t.length();

    if (len_s != len_t)
        return false;

    // S 到 T 的映射
    map<char, char> sTOtMap;
    for (int i = 0; i < len_s; i++) {
        char c_s = s.at(i);
        char c_t = t.at(i);
        if (sTOtMap.count(c_s) == 0) {
            sTOtMap[c_s] = c_t;
        } else {
            if (sTOtMap[c_s] != c_t) {    // 存在 一对多 情况，则返回false
                return false;
            }
        }
    }

    // T 到 S 的映射
    map<char, char> tTOsMap;
    for (int i = 0; i < len_s; i++) {
        char c_s = s.at(i);
        char c_t = t.at(i);
        if (tTOsMap.count(c_t) == 0) {
            tTOsMap[c_t] = c_s;
        } else {
            if (tTOsMap[c_t] != c_s) {    // 存在 一对多 情况，则返回false
                return false;
            }
        }
    }

    return true;
}

/**
 * 方法2.计算字符首次出现的下标
 * paper 与 title
 * paper中各字母首次出现下标的序列为: [0, 1, 0, 3, 4]，
 * title中各字母首次出现下标的序列为: [0, 1, 0, 3, 4]
 * 因为下标数组一致，所以两字符串同构。
 */
bool P0205_IsomorphicStrings::isIsomorphic_2(string s, string t) {
    int len_s = s.length();
    int len_t = t.length();

    if (len_s != len_t)
        return false;

    vector<int> index_s(len_s);
    for (int i = 0; i < len_s; i++) {
        index_s[i] = s.find(s[i]);
    }

    vector<int> index_t(len_t);
    for (int i = 0; i < len_t; i++) {
        index_t[i] = t.find(t[i]);
    }

    if (index_s == index_t) {
        return true;
    } else {
        return false;
    }
}


int P0205_IsomorphicStrings::test() {
    cout << isIsomorphic_2("ab", "aa") << endl;
    cout << isIsomorphic_2("egg", "add") << endl;
    cout << isIsomorphic_2("foo", "bar") << endl;
    cout << isIsomorphic_2("paper", "title") << endl;
    return 0;
}
