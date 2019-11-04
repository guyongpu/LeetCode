//
// Created by yongpu on 2019/11/4 9:59.
//

#include "P0056_MergeIntervals.h"

/**
 * 题目：合并区间
 * 描述：给出一个区间的集合，请合并所有重叠的区间.
 * 思路：先排序，然后遍历区间，不断合并区间，无法合并时保存结果.
 * 备注：掌握方法.
 */

bool Cmp_P0056(vector<int> a, vector<int> b) {
    if ((a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1])) {
        return true;
    }
    return false;
}

vector<vector<int>> P0056_MergeIntervals::merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), Cmp_P0056);
    vector<vector<int>> result;
    int len = intervals.size();
    int i = 0;
    while (i < len) {
        int start = intervals[i][0];                            // 新区间的start和end
        int end = intervals[i][1];

        while (i < len) {
            int temp_start = intervals[i][0];
            int temp_end = intervals[i][1];

            if (start <= temp_start && temp_start <= end) {     //可以合并，不断更新start和end
                if (temp_end <= end) { ;
                } else {
                    end = temp_end;
                }
                i++;
            } else {                                            //无法合并，则退出while循环
                break;
            }
        }

        vector<int> interval = {start, end};                    // 将 start和end存入到result中
        result.push_back(interval);
    }

    return result;
}

int P0056_MergeIntervals::test() {
    vector<vector<int>> intervals = {
            {1,  3},
            {2,  6},
            {8,  10},
            {15, 18},
    };
    vector<vector<int>> result = merge(intervals);

    int len = result.size();
    for (int i = 0; i < len; i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]" << endl;
    }


    return 0;
}
