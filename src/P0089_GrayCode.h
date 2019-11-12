//
// Created by yongpu on 2019/11/12 11:40.
//

#ifndef LEETCODE_P0089_GRAYCODE_H
#define LEETCODE_P0089_GRAYCODE_H

#include <iostream>
#include <vector>

using namespace std;

class P0089_GrayCode {
public:
    vector<int> grayCode(int n);

    void grayCode_Sub(vector<int> &result, int x,int flag,int times);

    int test();
};


#endif //LEETCODE_P0089_GRAYCODE_H
