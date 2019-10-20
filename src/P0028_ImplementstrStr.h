//
// Created by yongpu on 2019/10/18 16:54.
//

#ifndef LEETCODE_P0028_IMPLEMENTSTRSTR_H
#define LEETCODE_P0028_IMPLEMENTSTRSTR_H

#include <iostream>
#include <vector>

using namespace std;

class P0028_ImplementstrStr {
public:
    int strStr_1(string haystack, string needle);

    int strStr_2(string haystack, string needle);
    vector<int> cal_next(string needle);
    vector<int> cal_next_2(string needle);
    vector<int> move_next(vector<int> next);


    int test();
};


#endif //LEETCODE_P0028_IMPLEMENTSTRSTR_H
