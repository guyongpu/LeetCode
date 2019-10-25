//
// Created by yongpu on 2019/10/25 16:56.
//

#ifndef LEETCODE_P0037_SUDOKUSOLVER_H
#define LEETCODE_P0037_SUDOKUSOLVER_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class P0037_SudokuSolver {
public:
    void solveSudoku(vector<vector<char>> &board);

    int calBoxIndex(int i, int j);

    bool DFS_Sudoku(vector<vector<char>> &board,
                    vector<map<char, int> > &rowsMap,
                    vector<map<char, int> > &colsMap,
                    vector<map<char, int> > &boxsMap, int row, int col);

    int test();

};


#endif //LEETCODE_P0037_SUDOKUSOLVER_H
