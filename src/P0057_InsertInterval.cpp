//
// Created by yongpu on 2019/11/4 11:53.
//

#include "P0057_InsertInterval.h"

/**
 * 题目：插入区间
 * 描述：给出一个无重叠的 ，按照区间起始端点排序的区间列表，必要时合并区间.
 * 思路：方法1.直接加入区间，然后排序合并；方法2.找到新区间的位置，分3种情况，然后再合并，本题采用方法2.
 * 备注：方法2分情况要仔细.
 */

vector<vector<int>> P0057_InsertInterval::insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> result;
    int len = intervals.size();
    if (len == 0) {                     // 原区间为空，则直接插入并返回
        result.push_back(newInterval);
        return result;
    }

    int i = 0;
    int index = 0;
    while (i < len) {
        if (newInterval[0] < intervals[i][0]) {             // 情况1：在区间i的前面
            vector<int> temp_interval = {newInterval[0], 0};
            for (int j = i; j < len; j++) {
                if (newInterval[1] < intervals[j][0]) {     //在区间j的前面
                    temp_interval[1] = newInterval[1];
                    index = j;
                    break;
                } else if (intervals[j][0] <= newInterval[1] && newInterval[1] <= intervals[j][1]) {
                    temp_interval[1] = intervals[j][1];
                    index = j + 1;
                    break;
                } else {
                    if (j == len - 1) {
                        temp_interval[1] = newInterval[1];
                        index = j + 1;
                        break;
                    }
                }
            }
            result.push_back(temp_interval);
            break;
        } else if (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1]) {    // 情况2：在区间i的中间
            vector<int> temp_interval = {intervals[i][0], 0};
            for (int j = i; j < len; j++) {
                if (newInterval[1] < intervals[j][0]) {     //在区间j的前面
                    temp_interval[1] = newInterval[1];
                    index = j;
                    break;
                } else if (intervals[j][0] <= newInterval[1] && newInterval[1] <= intervals[j][1]) {    // 可以合并
                    temp_interval[1] = intervals[j][1];
                    index = j + 1;
                    break;
                } else {
                    if (j == len - 1) {
                        temp_interval[1] = newInterval[1];
                        index = j + 1;
                        break;
                    }
                }
            }
            result.push_back(temp_interval);    //将新区间插入
            break;
        } else {                            // 情况3：在区间i的外面
            result.push_back(intervals[i]);
            if (i == len - 1) {
                vector<int> temp_interval = {newInterval[0], newInterval[1]};
                result.push_back(temp_interval);
                index = i + 1;
            }
            i++;
        }
    }

    // 将j之后的区间拼接到result中
    for (int i = index; i < len; i++) {
        result.push_back(intervals[i]);
    }

    return result;
}

int P0057_InsertInterval::test() {
    vector<vector<int>> intervals = {
            {1,  2},
            {3,  5},
            {6,  7},
            {8,  10},
            {12, 16},
    };
    vector<int> newInterval = {4, 80};
    vector<vector<int>> result = insert(intervals, newInterval);
    int len = result.size();
    for (int i = 0; i < len; i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "], ";
    }
    cout << endl;
    return 0;
}
