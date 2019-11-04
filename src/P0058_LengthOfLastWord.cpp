//
// Created by yongpu on 2019/11/4 15:16.
//

#include "P0058_LengthOfLastWord.h"

/**
 * 题目：最后一个单词的长度
 * 描述：给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度.
 * 思路：方法1：去重空格得到str，然后计算；方法2：计算start和end，然后计算end-start.
 * 备注：掌握方法1和方法2
 */

int P0058_LengthOfLastWord::lengthOfLastWord_1(string s) {
    int len = s.length();
    if (len == 0) {
        return 0;
    }
    // 第一步，开始去除空格
    int index = 0;
    string str;
    str.push_back(s[index]);
    for (int i = index + 1; i < len; i++) {
        if (s[index] == ' ' && s[i] == ' ') {
            i = i;
        } else {
            str.push_back(s[i]);
            index = i;
        }
    }
    if (str[0] == ' ') {
        str.erase(str.begin());
    }
    if (str[str.length() - 1] == ' ') {
        str.erase(str.begin() + str.size() - 1);
    }

    // cout << "|" << str << "|" << endl;
    // 第二步，计算长度
    int len_str = str.length();
    int result = 0;
    for (int i = len_str - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            result = len_str - 1 - i;
            break;
        } else if (i == 0) {
            result = len_str;
        }
    }
    return result;
}

int P0058_LengthOfLastWord::lengthOfLastWord_2(string s) {
    int len = s.length();
    if (len == 0) {
        return 0;
    }
    int end = len - 1;
    while (end >= 0 && s[end] == ' ') {
        end--;
    }

    int start = end;
    while (start >= 0 && s[start] != ' ') {
        start--;
    }

    int result = end - start;

    return result;
}

int P0058_LengthOfLastWord::test() {
    cout << lengthOfLastWord_2("    He   llo     Wor    ld     ") << endl;
    cout << lengthOfLastWord_2("bac") << endl;
    cout << lengthOfLastWord_2("   ") << endl;
    cout << lengthOfLastWord_2(" ") << endl;
    cout << lengthOfLastWord_2("") << endl;
    return 0;
}
