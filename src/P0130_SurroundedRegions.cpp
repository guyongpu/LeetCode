//
// Created by yongpu on 2019/12/3 20:18.
//

#include "P0130_SurroundedRegions.h"

/**
 * 题目：被围绕的区域
 * 描述：给定一个二维的矩阵，包含 'X' 和 'O'（字母 O），找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充.
 * 思路：对每个边缘的点进行BFS，并进行标记为'T'。之后将所有'O'(为'O'说明与边缘不相通)变为'X'，将'T'(所有与边界相通的'O'已全部别标记)变为'O'即可.
 * 备注：也不可以不用标记法，将'T'的坐标存在hashset中亦可.
 */

void BFS(int x, int y, vector<vector<char>> &board) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
        return;
    }
    if (board[x][y] == 'O') {
        board[x][y] = 'T';           // 所有与边界相通的'O'已全部别标记为'T'
        BFS(x - 1, y, board); // 上
        BFS(x + 1, y, board); // 下
        BFS(x, y - 1, board); // 左
        BFS(x, y + 1, board); // 右
    }
}

void P0130_SurroundedRegions::solve(vector<vector<char>> &board) {
    if (board.size() == 0) {
        return;
    }
    int rows = board.size();
    int cols = board[0].size();

    // 遍历首列和末列
    for (int i = 0; i < rows; i++) {
        BFS(i, 0, board);
        BFS(i, cols - 1, board);
    }

    // 遍历首行和末行
    for (int j = 0; j < cols; j++) {
        BFS(0, j, board);
        BFS(rows-1, j, board);
    }

    // 二次遍历borad，将未被标记的'O'变为'X'，已被标记的'T'恢复为'O'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == 'T') {
                board[i][j] = 'O';
            }
        }
    }
}

int P0130_SurroundedRegions::test() {
    vector<vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
    };

    solve(board);

    return 0;
}
