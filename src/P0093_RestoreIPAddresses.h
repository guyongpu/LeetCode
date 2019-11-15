//
// Created by yongpu on 2019/11/15 21:09.
//

#ifndef LEETCODE_P0093_RESTOREIPADDRESSES_H
#define LEETCODE_P0093_RESTOREIPADDRESSES_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class P0093_RestoreIPAddresses {
public:
    vector<string> restoreIpAddresses(string s);
    void dfs(string s, int index, int times, int len, string temp, vector<string> &result);
    int test();
};


#endif //LEETCODE_P0093_RESTOREIPADDRESSES_H
