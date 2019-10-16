//
// Created by yongpu on 2019/10/15 19:08.
//

#include "P0010_RegularExpressionMatching.h"

/**
 * 题目：正则表达式匹配
 * 描述：给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配.
 * 思路：使用递归回溯方法，但是需要进行剪枝，否则会超时.
 * 备注：时常复习，容易忘记.
 *
 */


bool P0010_RegularExpressionMatching::isMatch(string s, string p) {
    int lens = s.length();
    int lenp = p.length();
    if (lens == 0 && lenp == 0)
        return true;
    if (lens != 0 && lenp == 0)
        return false;

    // 剪枝，目的是减少递归次数
    if (lens == 0) {   //如果s为空，则p必须长度为偶数，且第偶数位全部为*
        if (lenp % 2 == 1) {
            return false;
        } else {
            int i = 1;
            while(i<lenp){
                if(p.at(i) =='*'){
                    i = i+2;
                }
                else{
                    return false;
                }
            }
        }
    }

    //1.遇到*情况
    if (p.length() >= 2 && p.at(1) == '*') {
        //剪枝，消除类似a*a*a*中重复的a*,因为a*a*a*a*a*与a*的匹配结果一样。
        while (p.length() >= 4 && p.at(1) == '*' && p.at(0) == p.at(2) && p.at(1) == p.at(3)) {
            p = p.substr(2, p.length() - 2);
        }

        if ((s.length() > 0 && s.at(0) == p.at(0)) || (p.at(0) == '.' && s.length() != 0)) {
            bool flag1 = isMatch(s.substr(1, s.length() - 1), p);   //匹配s中的一个字符，p不变
            bool flag2 = isMatch(s.substr(1, s.length() - 1), p.substr(2, p.length() - 2)); //s,p各跳过一个字符
            bool flag3 = isMatch(s, p.substr(2, p.length() - 2));   //p跳过两个字符，s不变
            return (flag1 || flag2 || flag3);
        } else {
            bool flag4 = isMatch(s, p.substr(2, p.length() - 2));   //p跳过两个字符，s不变
            return flag4;
        }
    }

    //2.正常字符匹配情况
    if ((s.length() != 0 && s.at(0) == p.at(0)) || (s.length() != 0 && p.at(0) == '.')) {
        bool flag5 = isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1)); //s和p各跳过一个字符
        return flag5;
    } else {
        return false;
    }
}


int P0010_RegularExpressionMatching::test() {

    cout << isMatch("aa", "a") << endl;
    cout << isMatch("", ".*ba") << endl;
    cout << isMatch("ab", ".*c") << endl;
    cout << isMatch("aa", "..") << endl;
    cout << isMatch("aa", "") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << isMatch("mississippi", "mis*is*p*.") << endl;
    cout << isMatch("mississippi", "mississippi") << endl;
    cout << isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*b") << endl;

    return 0;
}
