//
// Created by yongpu on 2019/11/13 21:13.
//

#include "P0090_SubsetsII.h"

/**
 * 题目：子集II
 * 描述：给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 思路：先对数组进行排序，然后分别找长度为[1,len]的子集，dfs深搜，需要去重。
 * 备注：需要去重
 */

void dfs(vector<int> nums, vector<vector<int>> &result, vector<int> path, int cuur, int len) {
    if (path.size() == len) {
        result.push_back(path);
    } else {
        int detectNum = 0;
        for (int i = cuur; i < nums.size(); i++) {
            if (nums.size() - i < len - path.size()) {      // 剪枝
                break;
            }
            if (i == cuur) {
                path.push_back(nums[i]);
                dfs(nums, result, path, i + 1, len);
                path.pop_back();
                detectNum = nums[i];
            } else {
                // 去除重复的
                if (nums[i] == detectNum) {
                    continue;
                } else {
                    path.push_back(nums[i]);
                    dfs(nums, result, path, i + 1, len);
                    path.pop_back();
                    detectNum = nums[i];
                }
            }
        }
    }

}

vector<vector<int>> P0090_SubsetsII::subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {vector<int>()};   //空集
    for (int i = 0; i < nums.size(); i++) {
        vector<int> path;
        dfs(nums, result, path, 0, i + 1);
    }
    return result;
}

int P0090_SubsetsII::test() {
    vector<int> nums = {1, 2, 2, 3};
    vector<vector<int>> result = subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
