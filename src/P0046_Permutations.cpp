//
// Created by yongpu on 2019/10/31 9:47.
//

#include "P0046_Permutations.h"

/**
 * 题目：全排列
 * 描述：给定一个没有重复数字的序列，返回其所有可能的全排列.
 * 思路：确定begin位置，然后将[begin,len-1]的元素与nums[begin]交换，递归，当begin=len-1，则得到一个结果.
 * 备注：元素各不相同，不需要考虑去重.
 */

vector<vector<int>> P0046_Permutations::permute(vector<int> &nums) {
    vector<vector<int>> result;
    int len = nums.size();
    if (nums.size() > 0) {
        permute_sub(result, nums, 0, len);
    }
    return result;
}

void P0046_Permutations::permute_sub(vector<vector<int>> &result, vector<int> nums, int begin, int len) {
    if (begin == len - 1) {
        result.push_back(nums);
    } else {
        for (int i = begin; i < len; i++) {     // 将[begin,len-1]的元素与nums[begin]交换
            vector<int> temp_nums = nums;
            swap(temp_nums[begin], temp_nums[i]);
            permute_sub(result, temp_nums, begin + 1, len);
        }
    }
}


int P0046_Permutations::test() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
