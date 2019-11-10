//
// Created by yongpu on 2019/11/10 14:43.
//

#include "P0078_Subsets.h"

/**
 * 题目：子集
 * 描述：给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）.
 * 思路：本题与77题做法相同，注意剪枝，对每种长度的情况进行考虑，然后DFS.
 * 备注：DFS遍历+剪枝
 */
void P0078_Subsets::dfs(vector<vector<int>> &result, vector<int> path, vector<int> nums, int curr, int len) {
    if (path.size() == len) {
        result.push_back(path);
    } else {
        int nums_size = nums.size();
        for (int i = curr; i < nums_size; i++) {
            if (nums_size - i + 1 >= len - path.size()) {     //剪枝
                path.push_back(nums[i]);
                dfs(result, path, nums, i + 1, len);
                path.pop_back();
            }
        }
    }
}

vector<vector<int>> P0078_Subsets::subsets(vector<int> &nums) {
    int len = nums.size();
    vector<vector<int>> result;
    for (int i = 0; i <= len; i++) {
        vector<int> path;
        cout << "i = " << i << endl;
        dfs(result, path, nums, 0, i);
    }
    return result;
}

int P0078_Subsets::test() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> result = subsets(nums);
    int len = result.size();
    cout << "len = " << len << endl;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
