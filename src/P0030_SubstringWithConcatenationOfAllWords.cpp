//
// Created by yongpu on 2019/10/22 9:14.
//

#include "P0030_SubstringWithConcatenationOfAllWords.h"

/**
 * 题目：串联所有单词的子串
 * 描述：给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置.
 * 思路：法1：滑动窗口+hashmap方法，当count=word_num时，成功.法2：计算words的字符串所有排列组合，然后查找，但是会超时.
 * 备注：主要掌握法1
 */

vector<int> P0030_SubstringWithConcatenationOfAllWords::findSubstring_1(string s, vector<string> &words) {
    vector<int> result;             //存放结果的数组
    if (s.length() == 0 || words.size() == 0) {
        return result;
    }

    //单词数组中的单词的大小，个数，以及总长度
    int one_word = words[0].length();
    int word_num = words.size();
    int all_lens = one_word * word_num;

    //建立单词->单词个数的映射
    map<string, int> wordMap;
    for (int i = 0; i < word_num; i++) {
        wordMap[words[i]]++;
    }

    for (int i = 0; i < one_word; i++) {
        //left和rigth表示窗口的左右边界，count用来统计匹配的单词个数
        int left = i, right = i, count = 0;
        map<string, int> wordMap_temp;
        //开始滑动窗口
        while (right + one_word <= s.length()) {
            //从s中提取一个单词拷贝到w中
            string str = s.substr(right, one_word);
            right = right + one_word;       //窗口右边界右移一个单词的长度

            if (wordMap[str] == 0) {           //此单词不在words中，表示匹配不成功,然后重置单词个数、窗口边界、以及wordMap_temp
                count = 0;
                left = right;
                wordMap_temp.clear();
            } else {                          //该单词匹配成功，添加到wordMap_temp中
                wordMap_temp[str]++;
                count++;
                while (1) {
                    if (wordMap_temp[str] > wordMap[str]) {   //一个单词匹配多次，需要缩小窗口，也就是left右移
                        string str_t = s.substr(left, one_word);
                        wordMap_temp[str_t]--;
                        count--;
                        left += one_word;
                    } else {
                        break;
                    }
                }
                if (count == word_num) {
                    result.push_back(left);
                }
            }
        }
    }

    return result;

}


void
P0030_SubstringWithConcatenationOfAllWords::findSubstring_sub(string s, vector<string> words, int index, string str,
                                                              vector<string> &strvec, map<string, int> &strMap) {
    if (index == words.size()) {
        if (strMap[str] == 0) {
            strvec.push_back(str);
            strMap[str]++;
        }
        return;
    }

    int lenWord1 = words[0].size() * words.size();
    int lenWord2 = words[0].size() * (words.size() - index);
    if (s.find(str) >= s.npos - lenWord1 - lenWord2) {
        return;
    }

    int len = words.size();
    for (int i = index; i < len; i++) {
        /*
        vector<string> words_copy = words;
        swap(words_copy[index], words_copy[i]);
        findSubstring_sub(s, words_copy, index + 1, str + words_copy[index], strvec, strMap);
         */
        swap(words[index], words[i]);
        findSubstring_sub(s, words, index + 1, str + words[index], strvec, strMap);
        swap(words[i], words[index]);
    }
}

int P0030_SubstringWithConcatenationOfAllWords::test() {
    string s = "a1ab2bc3ca1ab2bb2ba1ac3c";
    vector<string> words = {"a1a", "b2b", "c3c"};
//    vector<int> result = findSubstring_2(s, words);
    vector<int> result = findSubstring_1(s, words);
    int len = result.size();
    for (int i = 0; i < len; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
