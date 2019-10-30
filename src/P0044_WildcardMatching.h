//
// Created by yongpu on 2019/10/27 17:13.
//

#ifndef LEETCODE_P0044_WILDCARDMATCHING_H
#define LEETCODE_P0044_WILDCARDMATCHING_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class P0044_WildcardMatching {
public:
    bool isMatch_1(string s, string p);

    bool isMatch_2(string s, string p);
    bool isMatch_sub(string s, string p, int is, int ip);
    string dealStars(string p);

    int test();
};


#endif //LEETCODE_P0044_WILDCARDMATCHING_H
