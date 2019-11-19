//
// Created by yongpu on 2019/11/19 16:28.
//

#ifndef LEETCODE_P0097_INTERLEAVINGSTRING_H
#define LEETCODE_P0097_INTERLEAVINGSTRING_H

#include <iostream>
#include <vector>

using namespace std;

class P0097_InterleavingString {
public:
    bool isInterleave_1(string s1, string s2, string s3);
    bool isInterleave_sub(string s1, string s2, string s3, int p1, int p2, int p3);

    bool isInterleave_2(string s1, string s2, string s3);
    int test();
};


#endif //LEETCODE_P0097_INTERLEAVINGSTRING_H
