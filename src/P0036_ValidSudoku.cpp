//
// Created by yongpu on 2019/10/24 16:24.
//

#include "P0036_ValidSudoku.h"

bool P0036_ValidSudoku::isValidSudoku(vector<vector<char>> &board) {
    vector<map<char, int>> rowsSet(9);
    vector<map<char, int>> colsSet(9);
    vector<map<char, int>> boxsSet(9);

    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            char c = board[i][j];

            int index = 0;
            if (0 <= i && i <= 2) {
                if (0 <= j && j <= 2) {
                    index = 0;
                } else if (3 <= j && j <= 5) {
                    index = 1;
                } else {  // 6 -8
                    index = 2;
                }
            } else if (3 <= i && i <= 5) {
                if (0 <= j && j <= 2) {
                    index = 3;
                } else if (3 <= j && j <= 5) {
                    index = 4;
                } else {  // 6 -8
                    index = 5;
                }
            } else {  // 6 -8
                if (0 <= j && j <= 2) {
                    index = 6;
                } else if (3 <= j && j <= 5) {
                    index = 7;
                } else {  // 6 -8
                    index = 8;
                }
            }

            if (rowsSet[i].count(c) > 0 || colsSet[j].count(c) > 0 || boxsSet[index].count(c) > 0) {
                return false;
            } else {
                rowsSet[i][c] = 1;
                colsSet[j][c] = 1;
                boxsSet[index][c] = 1;
            }
        }
    }
    return true;
}

int P0036_ValidSudoku::test() {
    vector<vector<char>> board = {
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
    cout << isValidSudoku(board) << endl;

    return 0;
}
