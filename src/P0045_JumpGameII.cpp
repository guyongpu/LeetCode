//
// Created by yongpu on 2019/10/30 17:30.
//

#include "P0045_JumpGameII.h"

/**
 * 题目：跳跃游戏II
 * 描述：给定一个非负整数数组，你最初位于数组的第一个位置，数组中的每个元素代表可以跳跃的最大长度，使用最少的跳跃次数到达数组的最后一个位置.
 * 思路：方法1：从前往后找，在每跳的范围内找能到的下一跳最大位置，不断更新；方法2：从后往前，每次找第一个能到达endPos的下标，知道nums[0]>=endPos.
 * 备注：掌握两种方法，方法2会超时
 */

int P0045_JumpGameII::jump_1(vector<int> &nums) {
    if (nums.size() == 1) {                 // 只有一个元素，输出0
        return 0;
    }
    if (nums[0] >= nums.size() - 1) {       // num[0] >= len-1，输出1
        return 1;
    }

    int len = nums.size();
    int jumpCnt = 0;                        // 步数
    int endPos = 0;                         // 当前范围的边界
    int maxPos = 0;                         // 当前范围内下一步可以到的最大位置

    for (int i = 0; i < len; i++) {
        maxPos = max(maxPos, nums[i] + i);
        if (endPos == i) {                  // 已经到达边界
            endPos = maxPos;                // 更新下一步为边界值
            jumpCnt++;                      // 步数加1
            if (endPos >= len - 1) {            // 已经能到达len-1，则无需继续计算
                break;
            }
        }
    }

    return jumpCnt;
}

int P0045_JumpGameII::jump_2(vector<int> &nums) {
    if (nums.size() == 1) {
        return 0;
    }
    if (nums[0] >= nums.size() - 1) {
        return 1;
    }
    int len = nums.size();
    int jumpCnt = 0;
    int endPos = len - 1;


    while (1) {
        for (int i = 0; i < len; i++) {
            if (i + nums[i] >= endPos) {    // 从前往后找第一个大于endPos的位置
                jumpCnt++;
                endPos = i;
                break;
            }
        }
        if (nums[0] >= endPos) {           // 已经在nums[0]的范围内，则结束循环
            jumpCnt = jumpCnt + 1;
            break;
        }
    }
    return jumpCnt;
}

int P0045_JumpGameII::test() {
    vector<int> nums = {200, 3, 1, 1, 4};
    cout << jump_1(nums) << endl;
    return 0;
}
