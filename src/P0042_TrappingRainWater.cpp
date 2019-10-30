//
// Created by yongpu on 2019/10/26 13:12.
//

#include "P0042_TrappingRainWater.h"

/**
 * 题目：接雨水
 * 描述：给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水.
 * 思路：方法1-2.计算每个高度的存水量，累加;方法3-5.计算每个柱子的存水量，其中方法5采用双指针法，效率最高.
 * 备注：掌握5种方法.
 */


// 方法1.计算每个高度的储水量，步长为高度差(恰好能AC)
int P0042_TrappingRainWater::trap_1(vector<int> &height) {
    int minHigh = INT_MAX;
    unordered_map<int, int> highMap;
    vector<int> highVec;

    for (int i = 0; i < height.size(); i++) {
        if (highMap[height[i]] == 0) {
            minHigh = min(minHigh, height[i]);
            highVec.push_back(height[i]);
            highMap[height[i]] = 1;
        }
    }
    sort(highVec.begin(), highVec.end());

    int result = 0;

    int len = height.size();
    int highCnt = highVec.size();
    for (int i = 1; i < highCnt; i++) {
        int high_prev = highVec[i - 1];
        int high_curr = highVec[i];
        int pos_start = 0, pos_end = 0;
        bool flag_start = true, flag_end = true;
        while (1) {
            flag_start = false;
            for (int j = pos_end; j < len; j++) {
                if (height[j] >= high_curr) {
                    pos_start = j;
                    flag_start = true;
                    break;
                }
            }
            if (flag_start == false) {
                break;
            }

            flag_end = false;
            int sum2 = 0;
            for (int j = pos_start + 1; j < len; j++) {
                if (height[j] >= high_curr) {
                    pos_end = j;
                    flag_end = true;
                    break;
                } else {
                    sum2 = sum2 + high_curr - high_prev;
                }
            }
            if (flag_end == false) {
                break;
            }

            // flag_start 和 flag_end 都为 true
            // 计算[flag_start,flag_end]之间的和
            /*
            int sum = 0;
            for (int k = pos_start + 1; k < pos_end; k++) {
                if (height[k] < high_curr) {
                    sum = sum + high_curr - high_prev;
                }
            }*/
            result = result + sum2;
        }
    }
    return result;
}

// 方法2.计算每个高度的储水量，高度步长为1(超时)
int P0042_TrappingRainWater::trap_2(vector<int> &height) {
    int maxHigh = INT_MIN;
    int minHigh = INT_MAX;
    for (int i = 0; i < height.size(); i++) {
        maxHigh = max(maxHigh, height[i]);
        minHigh = min(minHigh, height[i]);
    }

    int result = 0;

    int len = height.size();
    for (int i = minHigh + 1; i <= maxHigh; i++) {
        int high_curr = i;
        int pos_start = 0, pos_end = 0;
        bool flag_start = true, flag_end = true;
        while (1) {
            flag_start = false;
            for (int j = pos_end; j < len; j++) {
                if (height[j] >= high_curr) {
                    pos_start = j;
                    flag_start = true;
                    break;
                }
            }
            if (flag_start == false) {
                break;
            }

            flag_end = false;
            for (int j = pos_start + 1; j < len; j++) {
                if (height[j] >= high_curr) {
                    pos_end = j;
                    flag_end = true;
                    break;
                }
            }
            if (flag_end == false) {
                break;
            }

            // flag_start 和 flag_end 都为 true
            // 计算[flag_start,flag_end]之间的和
            int sum = 0;
            for (int k = pos_start + 1; k < pos_end; k++) {
                if (height[k] < high_curr) {
                    sum++;
                }
            }
            result = result + sum;
        }
    }
    return result;
}

// 方法3.计算每个柱子的存水量，每次查找左右两边的最大值
int P0042_TrappingRainWater::trap_3(vector<int> &height) {
    int len = height.size();
    int result = 0;
    for (int i = 1; i < len - 1; i++) {
        int high_curr = height[i];

        int max_left = 0, max_right = 0;
        //向左找最大值
        for (int j = i; j >= 0; j--) { //Search the left part for max bar size
            max_left = max(max_left, height[j]);
        }
        //向右找最大值
        for (int j = i; j < len; j++) { //Search the right part for max bar size
            max_right = max(max_right, height[j]);
        }
        result = result + min(max_left, max_right) - height[i];
    }
    return result;
}

// 方法4.计算每个柱子的存水量，保存每个height[i]的左右最大值
int P0042_TrappingRainWater::trap_4(vector<int> &height) {
    int len = height.size();
    int result = 0;
    vector<int> left_max(len), right_max(len);
    left_max[0] = right_max[0] = height[0];
    for (int i = 1; i < len; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[len - 1] = height[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < len - 1; i++) {
        result = result + min(left_max[i], right_max[i]) - height[i];
    }
    return result;
}

// 方法5.双指针法，也是计算每个柱子的存水量，效率最好
int P0042_TrappingRainWater::trap_5(vector<int> &height) {
    int len = height.size();
    int left = 0;
    int right = len - 1;
    int result = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {     //右边的板子长,则左边的指针移动
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                result += (left_max - height[left]);
            }
            ++left;
        } else {                                //左边的板子长,则右边的指针移动
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                result += (right_max - height[right]);
            }
            --right;
        }
    }
    return result;
};

int P0042_TrappingRainWater::test() {
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; //6
    cout << trap_2(height1) << endl;

    vector<int> height2 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1, 5, 4, 2, 1, 3, 5, 6, 8, 9, 0, 2, 6, 9, 21}; //40
    cout << trap_2(height2) << endl;

    vector<int> height3 = {9, 0, 21}; //9
    cout << trap_2(height3) << endl;

    vector<int> height4 = {72, 2, 6, 4};
    cout << trap_2(height4) << endl;

    return 0;
}
