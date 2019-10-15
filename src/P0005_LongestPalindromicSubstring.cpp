//
// Created by yongpu on 2019/10/14 20:58.
//

#include "P0005_LongestPalindromicSubstring.h"

/**
 * 题目：最长回文子串
 * 描述：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000.
 * 思路：采用中心点扩展方法，遍历字符串，每次以(i,i)和(i,i+1)为中心点，遍历完后得到最长回文串.
 * 备注：需要掌握.
 */

string P0005_LongestPalindromicSubstring::longestPalindrome(string s) {
    int len = s.length();
    string result;
    if (len <= 0)
        return result;
    for (int i = 0; i < len; i++) {
        string temp1, temp2;
        int left, right;
        int pos1, pos2;
        // 以i为中心
        left = i;
        right = i;
        while (0 <= left && right <= len - 1) {
            if (s.at(left) == s.at(right)) {
                pos1 = left;
                pos2 = right;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        temp1 = s.substr(pos1, pos2 - pos1 + 1);

        // 以i,i+1为中心
        left = i;
        right = i + 1;
        while (0 <= left && right <= len - 1) {
            if (s.at(left) == s.at(right)) {
                pos1 = left;
                pos2 = right;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        temp2 = s.substr(pos1, pos2 - pos1 + 1);

        if (temp1.length() > result.length()) {
            result = temp1;
        }
        if (temp2.length() > result.length()) {
            result = temp2;
        }
    }

    return result;
}

int P0005_LongestPalindromicSubstring::test() {
    cout << longestPalindrome("") << endl;
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("abcddcba") << endl;
    return 0;
}
