//
// Created by yongpu on 2019/10/30 16:37.
//

#ifndef LEETCODE_P0055_JUMPGAME_H
#define LEETCODE_P0055_JUMPGAME_H

#include <iostream>
#include <vector>

using namespace std;

class P0055_JumpGame {
public:
    bool canJump_1(vector<int> &nums);

    bool canJump_2(vector<int> &nums);

    bool canJump_dfs(vector<int> nums, int pos);

    int test();
};


#endif //LEETCODE_P0055_JUMPGAME_H
