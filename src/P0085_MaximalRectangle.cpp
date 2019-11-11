//
// Created by yongpu on 2019/11/11 15:41.
//

#include "P0085_MaximalRectangle.h"

/**
 * 题目：最大矩形
 * 描述：给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积.
 * 思路：动态规划，dp[i][j] = {向左，向上，面积},本质上是将每个点作为矩形的右下角，然后寻找能构造出的最大面积.
 * 备注：记住计算temp_area的原理
 */

int P0085_MaximalRectangle::maximalRectangle(vector<vector<char>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        return 0;
    }
    int cols = matrix[0].size();

    // dp[i][j] = {向左，向上，面积}
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, {0, 0, 0}));

    int result = 0;

    // 初始化第一行和第一列
    if (matrix[0][0] == '1') {
        dp[0][0] = {1, 1, 1};
        result = 1;
    }

    // 第一列
    for (int i = 1; i < rows; i++) {
        if (matrix[i][0] == '0') {
            dp[i][0] = {0, 0, 0};
        } else {
            dp[i][0] = {1, 1 + dp[i - 1][0][1], 1 + dp[i - 1][0][1]};
            result = max(result, 1 + dp[i - 1][0][1]);
        }
    }
    // 第一行
    for (int j = 1; j < cols; j++) {
        if (matrix[0][j] == '0') {
            dp[0][j] = {0, 0, 0};
        } else {
            dp[0][j] = {1 + dp[0][j - 1][0], 1, 1 + dp[0][j - 1][0]};
            result = max(result, 1 + dp[0][j - 1][0]);
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == '0') {
                dp[i][j] = {0, 0, 0};
            } else {
                // 向左的长度 dp[i][j][0]
                dp[i][j][0] = dp[i][j - 1][0] + 1;

                // 向上的长度 dp[i][j][1]
                dp[i][j][1] = dp[i - 1][j][1] + 1;

                // dp[i][j]面积 dp[i][j][2]
                int temp_area = 0;

                // temp_area,遍历matrix[i][j]上方的每一个元素，计算一个最大值hight*width
                if(i==3 && j ==3){
                    int x=1;
                }
                int width = dp[i][j][0];
                int hight;
                for (int k = i; k >=0 && matrix[k][j] == '1'; k--) {
                    hight = i - k + 1;
                    width = min(dp[k][j][0], width);    // 向左的长度
                    temp_area = max(temp_area, hight * width);
                }
                dp[i][j][2] = temp_area;
                result = max(result, temp_area);
            }
        }
    }
    /*
    // 输出dp矩阵
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "{" << dp[i][j][0] << "," << dp[i][j][1] << "," << dp[i][j][2] << "}  ";
        }
        cout << endl;
    }
    cout << endl;
     */

    return result;
}

int P0085_MaximalRectangle::test() {
    vector<vector<char>> matrix1 = {
            {'1', '0', '1', '0', '0',},
            {'1', '0', '1', '1', '1',},
            {'1', '1', '1', '1', '1',},
            {'1', '0', '0', '1', '0',},

    };
    vector<vector<char>> matrix = {
            {'0', '1', '1', '0', '1',},
            {'1', '1', '0', '1', '0',},
            {'0', '1', '1', '1', '0',},
            {'1', '1', '1', '1', '0',},
            {'1', '1', '1', '1', '1',},
            {'0', '0', '0', '0', '0',},

    };
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
