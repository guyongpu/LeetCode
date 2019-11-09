//
// Created by yongpu on 2019/11/9 14:53.
//

#include "P0073_SetMatrixZeroes.h"

/**
 * 题目：矩阵置零
 * 描述：给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法.
 * 思路：先将0的行列号用map记录，第二次遍历时进行修改.
 * 备注：也可以不用额外空间，比如遍历第i行时对第i-1行置零，使得一次遍历完成置零.
 */

void P0073_SetMatrixZeroes::setZeroes(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 0) {
        return;
    }
    int m = matrix[0].size();

    unordered_map<int, bool> rowMap(n);
    unordered_map<int, bool> colMap(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                rowMap[i] = true;
                colMap[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rowMap[i] == true || colMap[j] == true) {
                matrix[i][j] = 0;
            }
        }
    }

}

int P0073_SetMatrixZeroes::test() {
    vector<vector<int>> matrix = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1},
    };

    setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
