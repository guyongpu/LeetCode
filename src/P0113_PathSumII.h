//
// Created by yongpu on 2019/11/22 15:54.
//

#ifndef LEETCODE_P0113_PATHSUMII_H
#define LEETCODE_P0113_PATHSUMII_H

#include <iostream>
#include <vector>
#include "P0000_CommonHead.h"

using namespace std;

class P0113_PathSumII {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum);

    void dfs(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &result);

    int test();
};


#endif //LEETCODE_P0113_PATHSUMII_H
