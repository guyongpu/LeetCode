//
// Created by yongpu on 2019/11/11 11:00.
//

#include "P0084_LargestRectangleInHistogram.h"

/**
 * 题目：柱状图中最大的矩形
 * 描述：给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1.
 * 思路：计算每个高度往两边扩展的最大宽度，然后计算矩形面积，取最大值.
 * 备注：进行一定程度的剪枝
 */

int P0084_LargestRectangleInHistogram::largestRectangleArea(vector<int> &heights) {
    int len = heights.size();
    if (len == 0) {
        return 0;
    }
    int result = 0;
    int left, right;
    for (int i = 0; i < len; i++) {
        if (heights[i] == 0) {
            continue;
        }

        // 当heights[i] > heights[i-1] 时，需要从i开始扩展，否则可以使用上一次的结果
        if (i == 0 || heights[i] > heights[i - 1]) {
            left = i;
            right = i;
        }

        //向左扩展
        for (int j = left - 1; j >= 0; j--) {
            if (heights[j] >= heights[i]) {
                left = j;
                continue;
            } else {
                break;
            }
        }

        //向右扩展
        for (int j = right + 1; j < len; j++) {
            if (heights[j] >= heights[i]) {
                right = j;
                continue;
            } else {
                break;
            }
        }

        int width = right - left + 1;
        result = max(result, width * heights[i]);
    }

    return result;
}

int P0084_LargestRectangleInHistogram::test() {
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {4, 2, 0, 3, 2, 4, 3, 4};
    cout << largestRectangleArea(heights2) << endl;
    return 0;
}
