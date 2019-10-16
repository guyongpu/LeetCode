//
// Created by yongpu on 2019/10/15 15:09.
//

#include "P0011_ContainerWithMostWater.h"

/**
 * 题目：盛最多水的容器
 * 描述：给定n个非负整数a1，a2，...，an，每个数代表坐标中的一个点(i, ai)，求容器可以容纳最多的水.
 * 思路：法1：暴力法；法2：双指针法，较短的向较长的移动.
 * 备注：掌握双指针法
 */

//方法1：暴力解法，时间复杂度O(n^2)
int P0011_ContainerWithMostWater::maxArea_1(vector<int> &height) {
    int len = height.size();
    int result = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int area = h * w;
            result = max(result, area);
        }
    }
    return result;
}

//方法2：双指针法
int P0011_ContainerWithMostWater::maxArea_2(vector<int> &height) {
    int len = height.size();
    int result = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        result = max(result, h * w);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}

int P0011_ContainerWithMostWater::test() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea_1(height) << endl;
    cout << maxArea_2(height) << endl;
    return 0;
}
