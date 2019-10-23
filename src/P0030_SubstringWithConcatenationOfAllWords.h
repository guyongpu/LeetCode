//
// Created by yongpu on 2019/10/22 9:14.
//

#ifndef LEETCODE_P0030_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H
#define LEETCODE_P0030_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class P0030_SubstringWithConcatenationOfAllWords {
public:
    vector<int> findSubstring_1(string s, vector<string> &words);

    vector<int> findSubstring_2(string s, vector<string> &words);
    void findSubstring_sub(string s,vector<string> words, int index, string str, vector<string> &strvec,map<string,int> &strMap);



    int test();

};


#endif //LEETCODE_P0030_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H
