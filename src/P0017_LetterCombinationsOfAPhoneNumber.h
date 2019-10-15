//
// Created by yongpu on 2019/10/14 14:50.
//

#ifndef LEETCODE_P0017_LETTERCOMBINATIONSOFAPHONENUMBER_H
#define LEETCODE_P0017_LETTERCOMBINATIONSOFAPHONENUMBER_H

#include <iostream>
#include <vector>

using namespace std;

class P0017_LetterCombinationsOfAPhoneNumber {
public:
    vector<string> letterCombinations(string digits);

    void
    letterCombinations_sub(vector<string> &result, string digits, string temp, vector<vector<string>> charTable,
                           int index);

    int test();
};


#endif //LEETCODE_P0017_LETTERCOMBINATIONSOFAPHONENUMBER_H
