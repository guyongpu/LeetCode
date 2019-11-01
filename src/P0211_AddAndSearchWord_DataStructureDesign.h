//
// Created by yongpu on 2019/11/1 11:36.
//

#ifndef LEETCODE_P0211_ADDANDSEARCHWORD_DATASTRUCTUREDESIGN_H
#define LEETCODE_P0211_ADDANDSEARCHWORD_DATASTRUCTUREDESIGN_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class P0211_AddAndSearchWord_DataStructureDesign {
public:
    unordered_map<int,vector<string>> mapDict;

    P0211_AddAndSearchWord_DataStructureDesign() {

    }

    void addWord(string word);

    bool search(string word);

    int test();
};


#endif //LEETCODE_P0211_ADDANDSEARCHWORD_DATASTRUCTUREDESIGN_H
