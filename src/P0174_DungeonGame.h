//
// Created by yongpu on 2019/10/16 16:37.
//

#ifndef LEETCODE_P0174_DUNGEONGAME_H
#define LEETCODE_P0174_DUNGEONGAME_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class P0174_DungeonGame {
public:
    int times;
    int calculateMinimumHP(vector<vector<int>> &dungeon);

    void
    calculateMinimumHP_Sub(vector<vector<int>> &dungeon, vector<vector<int>> &cost,vector<vector<int>> &cost2, int HP_curr, int HP_sum, int &minHP,
                            int i, int j, int rows,
                           int cols);

    int test();
};


#endif //LEETCODE_P0174_DUNGEONGAME_H
