//
// Created by yongpu on 2019/10/30 16:37.
//

#include "P0055_JumpGame.h"

/**
 * 题目：跳跃游戏
 * 描述：给定一个非负整数数组，你最初位于数组的第一个位置，数组中的每个元素代表你在该位置可以跳跃的最大长度，判断你是否能够到达最后一个位置.
 * 思路：方法1：回溯，不断回溯，直到走到nums.size()-1；方法2：贪心，不断更新nums[0]能到达的最大位置.
 * 备注：使用贪心算法或者递归回溯.
 */

// 方法1：贪心算法
bool P0055_JumpGame::canJump_1(vector<int> &nums) {
    int len = nums.size();
    int maxPos = nums[0];
    for (int i = 1; i < len; i++) {
        int temp = i + nums[i];
        // 更新的maxPos
        if (maxPos >= i) {
            maxPos = max(temp, maxPos);
        }
    }
    cout << maxPos << endl;
    if (maxPos >= len - 1) {
        return true;
    }
    return false;
}

// 方法2：递归回溯
bool P0055_JumpGame::canJump_2(vector<int> &nums) {
    bool result = canJump_dfs(nums, 0);
    return result;
}

bool P0055_JumpGame::canJump_dfs(vector<int> nums, int pos) {
    if (pos == nums.size() - 1) {
        return true;
    }

    for (int i = 1; i <= nums[i];i++) {
        int nextPos = pos + i;
        if(nextPos > nums.size() - 1){
            break;
        }
        return canJump_dfs(nums, nextPos);
    }
    return false;
}

int P0055_JumpGame::test() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << canJump_2(nums1) << endl;

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << canJump_2(nums2) << endl;
    return 0;
}
