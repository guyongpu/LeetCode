//
// Created by yongpu on 2019/10/31 11:23.
//

#include "P0048_RotateImage.h"

/**
 * 题目：旋转图像
 * 描述：给定一个 n × n 的二维矩阵表示一个图像，将图像顺时针旋转 90 度.
 * 思路：方法1：借用额外数组;方法2：分三步实现；方法3：每次旋转一圈
 * 备注：掌握三种方法.
 */


// 方法1，借用额外二维矩阵
void P0048_RotateImage::rotate_1(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // 输出，从下到上，输出每一列，即为旋转的效果
    /**
     *  1 2 3
     *  4 5 6
     *  7 8 9
     *  输出：7 4 1 -> 8 5 2-> 9 6 3
     */
    /*
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    vector<vector<int>> matrix_rotate(n, vector<int>(n, 0));
    int cnt = 0;
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            int ir = cnt / n;
            int jr = cnt % n;
            matrix_rotate[ir][jr] = matrix[i][j];
            cnt++;
        }
    }
    matrix = matrix_rotate;
}

// 方法2，原地旋转
void P0048_RotateImage::rotate_2(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int cycle = n / 2;  //有几圈
    for (int k = 0; k < cycle; k++) {
        // 左上角(k,k) 右下角(n-1-k,n-1-k)
        // 第一步，将上下两行交换，即[k][k---n-1-k] 与 [n-1-k][k---n-1-k]上下交换
        for (int j = k; j <= n - 1 - k; j++) {
            swap(matrix[k][j], matrix[n - 1 - k][j]);
        }
        //第二步，对左右两列的元素进行上下交换,[k+i][k] 与[n-1-k-i][k]交换,[k+i][n-1-k] 与[n-1-k-i][n-1-k]交换
        int cnt = (n - 1 - k - k) / 2;
        for (int i = 1; i <= cnt; i++) {
            swap(matrix[k + i][k], matrix[n - 1 - k - i][k]);
            swap(matrix[k + i][n - 1 - k], matrix[n - 1 - k - i][n - 1 - k]);
        }

        // 第三步，斜对角交换，即 [k][k+1]与[k+1][k]交换
        for (int j = k; j <= n - 1 - k; j++) {      //横向，上面的行与左边的列交换
            swap(matrix[k][j], matrix[j][k]);
        }
        for (int i = k + 1; i <= n - 1 - k; i++) {   //纵向，右边的列与下边的行交换，注意i从k+1开始，避免左上角被交换两次
            swap(matrix[i][n - 1 - k], matrix[n - 1 - k][i]);
        }
    }
}

// 方法3,在单次循环中旋转4个矩阵
void P0048_RotateImage::rotate_3(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int cycle = n / 2;  //有几圈

    for (int i = 0; i < cycle; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            //  1 0 2       3 0 1
            //  0 0 0  ->   0 0 0
            //  3 0 4       4 0 2
            int temp1 = matrix[i][j];
            int temp2 = matrix[j][n - 1 - i];
            int temp3 = matrix[n - 1 - j][i];
            int temp4 = matrix[n - 1 - i][n - j - 1];

            matrix[i][j] = temp3;
            matrix[j][n - 1 - i] = temp1;
            matrix[n - 1 - j][i] = temp4;
            matrix[n - 1 - i][n - j - 1] = temp2;
        }
    }
}

int P0048_RotateImage::test() {
    vector<vector<int>> matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    vector<vector<int>> matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };

    vector<vector<int>> matrix2 = {
            {1, 2},
            {3, 4}
    };

    // 旋转前
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    rotate_3(matrix);

    // 旋转后
    cout << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
