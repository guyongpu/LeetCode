//
// Created by yongpu on 2019/11/23 20:51.
//

#include "P0119_Pascal_TriangleII.h"

/**
 * 题目：杨辉三角II
 * 描述：给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行.
 * 思路：在计算普通杨辉三角的基础上，将上一行的结果进行保存，用于计算下一行的结果.
 * 备注：常规思路
 */

vector<int> P0119_Pascal_TriangleII::getRow(int rowIndex) {
    vector<int> result;
    for (int i = 0; i <= rowIndex; i++) {
        vector<int> temp;
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1) {
                temp.push_back(1);
            } else {
                int num = result[j - 1] + result[j];
                temp.push_back(num);
            }
        }
        result = temp;
    }
    return result;
}

int P0119_Pascal_TriangleII::test() {
    vector<int> result = getRow(10);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
