//
// Created by yongpu on 2019/10/31 10:22.
//

#include "P0047_PermutationsII.h"

/**
 * 题目：全排列II
 * 描述：给定一个可包含重复数字的序列，返回所有不重复的全排列.
 * 思路：方法1：直接find去重；方法2：在普通全排列的基础上增加isRepeat检测[begin,i)之间是否存在nums[index]，存在则跳过.其他不变
 * 备注：掌握方法1和方法2
 */

// 方法1：直接使用find去重
vector<vector<int>> P0047_PermutationsII::permuteUnique_1(vector<int> &nums) {
    vector<vector<int>> result;
    int len = nums.size();
    if (len > 0) {
        permuteUnique_1_sub(result, nums, 0, len);
    }
    return result;
}

void P0047_PermutationsII::permuteUnique_1_sub(vector<vector<int>> &result, vector<int> nums, int begin, int len) {
    if (begin == len - 1) {
        if (find(result.begin(), result.end(), nums) == result.end()) {
            result.push_back(nums);
        }
    } else {
        for (int i = begin; i < len; i++) {
            vector<int> temp_nums = nums;
            swap(temp_nums[begin], temp_nums[i]);
            permuteUnique_1_sub(result, temp_nums, begin + 1, len);
        }
    }
}

/**********************************************************/
// 方法2：在计算过程中去重
vector<vector<int>> P0047_PermutationsII::permuteUnique_2(vector<int> &nums) {
    vector<vector<int>> result;
    int len = nums.size();
    if (len > 0) {
        permuteUnique_2_sub(result, nums, 0, len);
    }
    return result;
}

// 检查[begin,index)之间是否有元素等于nums[index]
bool P0047_PermutationsII::isRepeat(vector<int> nums, int begin, int index) {
    int temp = nums[index];
    for (int i = begin; i < index; i++) {
        if (nums[i] == temp) {
            return true;
        }
    }
    return false;
}

void P0047_PermutationsII::permuteUnique_2_sub(vector<vector<int>> &result, vector<int> nums, int begin, int len) {
    if (begin == len - 1) {
        result.push_back(nums);
    } else {
        for (int i = begin; i < len; i++) {
            vector<int> temp_nums = nums;
            if (isRepeat(temp_nums, begin, i) == true) {    //检查[begin,i)之间是否有元素等于nums[i]，有则跳过
                continue;
            }
            swap(temp_nums[begin], temp_nums[i]);
            permuteUnique_2_sub(result, temp_nums, begin + 1, len);
        }
    }
}


int P0047_PermutationsII::test() {
    vector<int> nums = {1, 3, 3};
    vector<vector<int>> result = permuteUnique_2(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

