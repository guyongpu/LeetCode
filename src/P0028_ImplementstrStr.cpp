//
// Created by yongpu on 2019/10/18 16:54.
//

#include "P0028_ImplementstrStr.h"

/**
 * 题目：实现strStr()
 * 描述：实现 strStr()函数。给定一个haystack字符串和一个needle字符串，在haystack 字符串中找出needle字符串出现的第一个位置(从0开始)。如果不存在，则返回-1.
 * 思路：法1：暴力法BF，双重循环求解；法2：KMP算法，(1)计算next数组;(2)右移next数组;(3)字符串匹配;
 * 备注：KMP计算next数组是重点（常规/进阶）
 */

// 暴力法
int P0028_ImplementstrStr::strStr_1(string haystack, string needle) {
    int len1 = haystack.length();
    int len2 = needle.length();

    if (len2 > len1)
        return -1;
    if (len2 == 0)
        return 0;

    int index = -1;
    bool flag = false;
    for (int i = 0; i < len1 - len2 + 1; i++) {
        int temp_i = i;
        for (int j = 0; j < len2; j++) {
            flag = true;
            index = i;
            if (haystack[temp_i] != needle[j]) {
                flag = false;
                break;
            }
            temp_i++;
        }
        if (flag == true) {
            break;
        }
    }
    if (flag == false)
        index = -1;

    return index;
}

/****************************************************************/

//法2：KMP算法求解
int P0028_ImplementstrStr::strStr_2(string haystack, string needle) {
    int len1 = haystack.length();
    int len2 = needle.length();
    if (len2 == 0)
        return 0;
    if (len2 > len1)
        return -1;

    //开始KMP算法
    vector<int> next = cal_next(needle);        //进阶方法计算next数组
    //vector<int> next = cal_next_2(needle);    //普通方法计算next数组
    next = move_next(next);                     //将next数组向右移动一位

    int i = 0;
    int j = 0;
    int result = -1;
    while (i < len1) {
        if (j == len2 - 1 && haystack[i] == needle[j]) {
            result = i - j;
            break;
        }
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = next[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
    }
    return result;
}

//进阶方法计算next
vector<int> P0028_ImplementstrStr::cal_next(string needle) {
    int len = needle.length();
    vector<int> next(len, 0);

    next[0] = 0;
    int val = 0;
    int i = 1;
    while (i < len) {
        if (needle[i] == needle[val]) {
            val++;
            next[i] = val;
            i++;
        } else {
            if (val > 0) {
                val = next[val - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }

    }
    return next;
}

//常规方法计算next
vector<int> P0028_ImplementstrStr::cal_next_2(string needle) {
    int len = needle.length();
    vector<int> next(len, 0);
    for (int i = 0; i < len; i++) {
        string substr = needle.substr(0, i + 1);
        //对substr求前后缀
        int len_sub = substr.length();
        for (int j = len_sub - 1; j > 0; j--) {                 //j为后缀长度
            string str_front = substr.substr(0, j);
            string str_last = substr.substr(len_sub - j, j);
            if (str_front == str_last) {
                next[i] = j;
                break;
            }
        }
    }
    return next;
}


vector<int> P0028_ImplementstrStr::move_next(vector<int> next) {
    int len = next.size();
    for (int i = len - 1; i > 0; i--) {
        next[i] = next[i - 1];
    }
    next[0] = -1;
    return next;
}

int P0028_ImplementstrStr::test() {
    cout << strStr_1("hello", "hello1") << endl;
    cout << strStr_2("hello", "hello1") << endl;
    cout << strStr_1("", "") << endl;
    cout << strStr_2("", "") << endl;
    cout << strStr_1("", "1") << endl;
    cout << strStr_2("", "1") << endl;
    cout << strStr_1("a", "") << endl;
    cout << strStr_2("a", "") << endl;

    vector<int> next1 = cal_next("ABABABBAABABABBAABABABABBA");
    vector<int> next2 = cal_next_2("ABABABBAABABABBAABABABABBA");

    int len = next1.size();
    for(int i = 0 ; i < len ;i++){
        cout << next1[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < len ;i++){
        cout << next2[i] << " ";
    }
    cout << endl;
    return 0;
}