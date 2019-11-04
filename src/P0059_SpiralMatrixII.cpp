//
// Created by yongpu on 2019/11/4 16:12.
//

#include "P0059_SpiralMatrixII.h"

/**
 * 题目：螺旋矩阵II
 * 描述：给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵.
 * 思路：安装遍历的思路给每个坐标赋值即可.
 * 备注：掌握遍历结束条件.
 */

vector<vector<int>> P0059_SpiralMatrixII::generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int cnt = 1;

    int pos1_x = 0;
    int pos1_y = 0;

    int pos2_x = n - 1;
    int pos2_y = n - 1;

    while (pos1_x <= pos2_x && pos1_y <= pos2_y) {
        // 左->右,[pos1_x,pos1_y]到[pos1_x,pos2_y]
        for (int j = pos1_y; j <= pos2_y; j++) {
            result[pos1_x][j] = cnt;
            cnt++;
        }
        if (cnt == n * n + 1) {         //可以结束循环
            break;
        }

        // 上->下,[pos1_x+1,pos2_y]到[pos2_x-1,pos2_y]
        for (int i = pos1_x + 1; i <= pos2_x - 1; i++) {
            result[i][pos2_y] = cnt;
            cnt++;
        }

        // 右->左,[pos2_x,pos2_y]到[pos2_x,pos1_y]
        for (int j = pos2_y; j >= pos1_y; j--) {
            result[pos2_x][j] = cnt;
            cnt++;
        }


        // 下->上,[pos2_x-1,pos1_y]到[pos1_x+1,pos1_y]
        for (int i = pos2_x - 1; i >= pos1_x + 1; i--) {
            result[i][pos1_y] = cnt;
            cnt++;
        }

        pos1_x++;
        pos1_y++;
        pos2_x--;
        pos2_y--;
    }


    return result;
}

int P0059_SpiralMatrixII::test() {
    vector<vector<int>> result = generateMatrix(4);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
