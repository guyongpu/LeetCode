//
// Created by yongpu on 2019/11/23 20:30.
//

#include "P0118_Pascal_Triangle.h"

/**
 * 题目：杨辉三角
 * 描述：给定一个非负整数 numRows，生成杨辉三角的前 numRows 行.
 * 思路：一个元素等于它的上面两个元素的和，思路比较简单.
 * 备注：掌握即可
 */

vector<vector<int>> P0118_Pascal_Triangle::generate(int numRows) {
    vector<vector<int>> result;
    for (int i = 1; i <= numRows; i++) {
        vector<int> temp;
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1) {
                temp.push_back(1);
            } else {
                int num = result[i - 2][j - 1] + result[i - 2][j];
                temp.push_back(num);
            }
        }
        result.push_back(temp);
    }
    return result;
}

int P0118_Pascal_Triangle::test() {
    vector<vector<int>> result = generate(5);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
