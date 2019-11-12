//
// Created by yongpu on 2019/11/12 10:46.
//

#include "P0087_ScrambleString.h"

/**
 * 题目：扰乱字符串
 * 描述：给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树.
 * 思路：使用递归，每次将s1和s2分别分开成[0,i)与[i,len-1]两部分进行递归，通过将字符串排序判断字符串组成是否相同.
 * 备注：递归判断，排序判断字符组成.
 */

bool P0087_ScrambleString::isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    if (s1 == s2) {
        return true;
    }

    string ss1(s1);
    string ss2(s2);
    sort(ss1.begin(), ss1.end());
    sort(ss2.begin(), ss2.end());

    // 判断s1与s2的字符组成是否相同
    if (ss1 != ss2) {
        return false;
    }

    for (int i = 1; i < s1.size(); i++) {
        //s1前i个字符 匹配 s2 前i个字符
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) {
            return true;
        }

        //s1前i个字符 匹配 s2 后i个字符
        if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
            isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i))) {
            return true;
        }

    }

    return false;
}

int P0087_ScrambleString::test() {
    cout << isScramble("great", "regta") << endl;
    return 0;
}
