//
// Created by yongpu on 2019/12/29 16:35.
//

#include "P0557_ReverseWordsInA_StringIII.h"

/**
 * 题目：反转字符串中的单词 III
 * 描述：给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序.
 * 思路：找到空格位置，然后使用双指针法对该段单词进行首尾交换.
 * 备注：掌握方法.
 */

string P0557_ReverseWordsInA_StringIII::reverseWords(string s) {
    if (s.size() == 0) {
        return s;
    }

    int start = 0;
    int end = -1;

    int left = 0;
    int right = 0;
    while (s.find(" ", end+1) != s.npos) {
        start = end+1;
        end = s.find(" ",end+1);
        // 反转start - end的字符
        left = start;
        right = end-1;
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }

    left = end+1;
    right = s.size()-1;
    while(left < right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
    return s;
}

int P0557_ReverseWordsInA_StringIII::test() {
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s) << endl;
    return 0;
}
