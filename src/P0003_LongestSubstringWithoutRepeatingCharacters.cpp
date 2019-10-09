//
// Created by yongpu on 2019/10/8.
//

#include "P0003_LongestSubstringWithoutRepeatingCharacters.h"

/**
 * 题目：无重复字符的最长子串
 * 描述：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度.
 * 思路：使用滑动窗口来做，记录队列最长的值
 * 备注：还可以使用map进行优化
 */

//滑动窗口做法
int P0003_LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(string s) {
    if (s.length() <= 1)
        return s.length();

    vector<char> strque;                     //滑动窗口
    int maxLen = 0;
    int len_str = s.length();
    for (int i = 0; i < len_str; i++) {

        int len_que = strque.size();
        bool flag = true;
        int index = 0;
        for (int j = 0; j < len_que; j++) { //查找队列中是否存在该元素
            if (s[i] == strque[j]) {
                flag = false;
                index = j;
                break;
            }
        }
        if (flag == true) { // 不存在，则加入队列
            strque.push_back(s[i]);
            maxLen = max(maxLen, (int) strque.size());
        } else {             //存在，则删除下标为[0,index]范围内元素
            strque.erase(strque.begin(), strque.begin() + index + 1);
            //将s[i]加入窗口中
            strque.push_back(s[i]);
            maxLen = max(maxLen, (int) strque.size());
        }

    }
    return maxLen;
}

int P0003_LongestSubstringWithoutRepeatingCharacters::test() {

    cout << lengthOfLongestSubstring("abcabcbb") << endl;       //3
    cout << lengthOfLongestSubstring("bbbbb") << endl;          //1
    cout << lengthOfLongestSubstring("pwwkew") << endl;         //3
    cout << lengthOfLongestSubstring("aab") << endl;            //2
    cout << lengthOfLongestSubstring("a") << endl;              //1
    cout << lengthOfLongestSubstring("au") << endl;             //2
    cout << lengthOfLongestSubstring("auk") << endl;            //3
    return 0;
}
