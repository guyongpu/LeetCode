//
// Created by yongpu on 2019/10/25 16:56.
//

#include "P0037_SudokuSolver.h"

/**
 * 题目：解数独
 * 描述：编写一个程序，通过已填充的空格来解决数独问题.
 * 思路：在P0036的基础上做，rowsMap,colsMap,boxsMap,最后用上DFS算法进行求解.
 * 备注：DFS重要题目.
 */

int P0037_SudokuSolver::calBoxIndex(int i, int j) {
    int index = 0;
    if (0 <= i && i < 3) {
        if (0 <= j && j < 3) {
            index = 0;
        } else if (3 <= j && j < 6) {
            index = 1;
        } else {
            index = 2;
        }
    } else if (3 <= i && i < 6) {
        if (0 <= j && j < 3) {
            index = 3;
        } else if (3 <= j && j < 6) {
            index = 4;
        } else {
            index = 5;
        }
    } else {
        if (0 <= j && j < 3) {
            index = 6;
        } else if (3 <= j && j < 6) {
            index = 7;
        } else {
            index = 8;
        }
    }
    return index;
}

bool P0037_SudokuSolver::DFS_Sudoku(vector<vector<char>> &board,
                                    vector<map<char, int> > &rowsMap,
                                    vector<map<char, int> > &colsMap,
                                    vector<map<char, int> > &boxsMap, int row, int col) {
    // 边界校验, 如果已经填充完成, 返回true, 表示一切结束
    if (col == 9) {
        col = 0;
        row++;
        if (row == 9) {
            return true;
        }
    }

    // 是空则尝试填充, 否则跳过继续尝试填充下一个位置
    if (board[row][col] == '.') {
        for (int i = 0; i < 9; i++) {
            char ans = '1' + i;
            int idx = calBoxIndex(row, col);
//            if (rowsMap[row].count(ans) == 0 && colsMap[col].count(ans) == 0 && boxsMap[index].count(ans) == 0) {
            if (rowsMap[row][ans] == 0 && colsMap[col][ans] == 0 && boxsMap[idx][ans] == 0) {
                rowsMap[row][ans] = 1;
                colsMap[col][ans] = 1;
                boxsMap[idx][ans] = 1;
                board[row][col] = ans;
                if (DFS_Sudoku(board, rowsMap, colsMap, boxsMap, row, col + 1) == true) {
//                    cout << "finish" << endl;
                    return true;
                }
                /*
                rowsMap[row].erase(ans);
                colsMap[col].erase(ans);
                boxsMap[index].erase(ans);*/

                rowsMap[row][ans] = 0;
                colsMap[col][ans] = 0;
                boxsMap[idx][ans] = 0;
                board[row][col] = '.';
            }
        }

    } else {
        return DFS_Sudoku(board, rowsMap, colsMap, boxsMap, row, col + 1);
    }
    return false;
}

void P0037_SudokuSolver::solveSudoku(vector<vector<char>> &board) {
    int rows = board.size();        //9
    int cols = board[0].size();     //9
    int boxs = rows * cols / 9;     //9

    vector<map<char, int> > rowsMap(rows);
    vector<map<char, int> > colsMap(cols);
    vector<map<char, int> > boxsMap(boxs);


    //进行记录
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char c = board[i][j];
            if (c != '.') {
                //计算index的值
                int idx = calBoxIndex(i, j);
                rowsMap[i][c] = 1;
                colsMap[j][c] = 1;
                boxsMap[idx][c] = 1;
            }
        }
    }

    //开始填数据
    DFS_Sudoku(board, rowsMap, colsMap, boxsMap, 0, 0);
}

int P0037_SudokuSolver::test() {
    vector<vector<char>> board1 = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    vector<vector<char>> board2 = {
            {'5', '.', '.', '6', '7', '8', '9', '1', '2'},
            {'6', '.', '.', '1', '9', '5', '3', '4', '8'},
            {'.', '9', '8', '3', '4', '2', '5', '6', '7'},
            {'8', '.', '.', '7', '6', '1', '4', '2', '3'},
            {'4', '.', '.', '8', '5', '3', '7', '9', '1'},
            {'7', '.', '.', '9', '2', '4', '8', '0', '6'},
            {'9', '6', '.', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };

    vector<vector<char>> board_test = board1;
    solveSudoku(board_test);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board_test[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
