//
// Created by yongpu on 2019/11/3 18:53.
//

#include "P0054_SpiralMatrix.h"

/**
 * 题目：旋转矩阵
 * 描述：给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素.
 * 思路：定位[pos1_row,pos1_col]和[pos2_row,pos2_col]，然后遍历一圈，当pos1_row=pos2_row或pos1_row=pos2_row时，结束循环，再进行截取.
 * 备注：掌握定位点和循环结束条件，已经最后的截取
 */

vector<int> P0054_SpiralMatrix::spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
        return vector<int>();
    }
    int m = matrix.size();      // 行数
    int n = matrix[0].size();   // 列数

    int pos1_row = 0;
    int pos1_col = 0;
    int pos2_row = m - 1;
    int pos2_col = n - 1;

    vector<int> result;
    while (pos1_row <= pos2_row && pos1_col <= pos2_col) {
        // 从左到右输出  [pos1_row,pos1_col] -> [pos1_row,pos2_col]
        for (int j = pos1_col; j <= pos2_col; j++) {
            result.push_back(matrix[pos1_row][j]);
        }

        // 从上到下输出  [pos1_row+1,pos2_col] -> [pos2_row-1,pos2_col]
        for (int i = pos1_row + 1; i <= pos2_row - 1; i++) {
            result.push_back(matrix[i][pos2_col]);
        }

        // 从右到左输出  [pos2_row,pos2_col] -> [pos2_row,pos1_col]
        for (int j = pos2_col; j >= pos1_col; j--) {
            result.push_back(matrix[pos2_row][j]);
        }

        // 从下到上输出  [pos2_row-1,pos1_col] -> [pos1_row+1,pos1_col]
        for (int i = pos2_row - 1; i >= pos1_row + 1; i--) {
            result.push_back(matrix[i][pos1_col]);
        }

        pos1_row++;
        pos1_col++;
        pos2_row--;
        pos2_col--;
    }

    int cnt = m * n;
    result.assign(result.begin(),result.begin()+cnt);

    return result;
}

int P0054_SpiralMatrix::test() {
    vector<vector<int>> matrix1{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    vector<vector<int>> matrix2{
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9,  10},
            {11, 12, 13, 14, 15}
    };

    vector<vector<int>> matrix3{
            {1,  2,  3},
            {4,  5,  6},
            {7,  8,  9},
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18},
    };

    vector<vector<int>> matrix4{
            {1, 0, 2},
            {4, 1, 5},
            {7, 2, 8},
            {9, 3, 10},
    };

    vector<int> result = spiralOrder(matrix3);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
