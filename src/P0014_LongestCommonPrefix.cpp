//
// Created by yongpu on 2019/10/15 9:21.
//

#include "P0014_LongestCommonPrefix.h"

/**
 * 题目：最长公共前缀
 * 描述：编写一个函数来查找字符串数组中的最长公共前缀，如果不存在公共前缀，返回空字符串 "".
 * 思路：法1：先找最短字符串的长度,minLen，然后i->minLen,直到不相等，则[0,index]为最长;法2：找两两间的最长公共串，结束即得到结果.
 * 备注：两种方法都要会
 */

/**方法1：先找最短字符串的长度,minLen，然后i->minLen,直到不相等，则[0,index]为最长.*/
string P0014_LongestCommonPrefix::longestCommonPrefix_1(vector<string> &strs) {
    string result;
    int strsSize = strs.size();
    if (strsSize == 0)
        return result;
    if (strsSize == 1)
        return strs[0];

    //找最短的字符串长度
    int minLen = INT_MAX;
    for (int i = 0; i < strsSize; i++) {
        minLen = min(minLen, (int) strs[i].length());
    }
    if (minLen == 0)
        return result;

    //开始计算，最后[0,index]为公共串
    int index = -1;
    for (int i = 0; i < minLen; i++) {
        bool flag = true;
        char c = strs[0].at(i);
        for (int j = 0; j < strsSize; j++) {
            if (strs[j].at(i) != c) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            index = i;
        } else {
            break;
        }
    }

    result = strs[0].substr(0, index + 1);

    return result;
}

/** 方法2：找两两间的最长公共串，结束即得到结果.*/
string P0014_LongestCommonPrefix::longestCommonPrefix_2(vector<string> &strs) {
    string result;
    int strsSize = strs.size();
    if (strsSize == 0)
        return result;
    if (strsSize == 1)
        return strs[0];

    result = strs[0];
    for (int i = 1; i < strsSize; i++) {
        int len = min(result.length(), strs[i].length());
        int index = -1;
        for (int j = 0; j < len; j++) {
            if (result.at(j) == strs[i].at(j)) {
                index = j;
            } else {
                break;
            }
        }
        if (index != -1) {      //更新公共前缀
            result = result.substr(0, index + 1);
        } else {
            result = "";
        }
    }
    return result;
}

int P0014_LongestCommonPrefix::test() {
    vector<string> strs = {"dogracecar", "dogracecar", ""};
    cout << longestCommonPrefix_1(strs) << endl;
    cout << longestCommonPrefix_2(strs) << endl;

    return 0;
}
