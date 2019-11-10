//
// Created by yongpu on 2019/11/10 17:42.
//

#include "P0079_WordSearch.h"

/**
 * 题目：单词搜索
 * 描述：给定一个二维网格和一个单词，找出该单词是否存在于网格中.
 * 思路：从每个点作为起点进行dfs，然后按常规思路进行DFS搜索，即可得到答案.
 * 备注：深度优先
 */

void
P0079_WordSearch::dfs(bool &result, vector<vector<char>> board, vector<vector<bool>> &flag, string word, int row, int col, int x, int y,
    int index) {
    if (result == true) {
        return;
    }
    if (index == word.length() - 1) {
        result = true;
    } else {
        flag[x][y] = false;
        if (board[x][y] == word[index]) {
            if (x < row - 1 && flag[x + 1][y] && word[index + 1] == board[x + 1][y]) {  // 往下
                dfs(result, board, flag, word, row, col, x + 1, y, index + 1);
            }
            if (x > 0 && flag[x - 1][y] && word[index + 1] == board[x - 1][y]) {        // 往上
                dfs(result, board, flag, word, row, col, x - 1, y, index + 1);
            }
            if (y < col - 1 && flag[x][y + 1] && word[index + 1] == board[x][y + 1]) {  // 往右
                dfs(result, board, flag, word, row, col, x, y + 1, index + 1);
            }
            if (y > 0 && flag[x][y - 1] && word[index + 1] == board[x][y - 1]) {        // 往左
                dfs(result, board, flag, word, row, col, x, y - 1, index + 1);
            }
        }
        flag[x][y] = true;
    }
}

bool P0079_WordSearch::exist(vector<vector<char>> &board, string word) {
    // n*n
    int n = board.size();
    if (n == 0) {
        return false;
    }
    int m = board[0].size();
    vector<vector<bool>> flag(n, vector<bool>(m, true));  // true 表示还未访问

    bool result = false;
    for (int i = 0; i < n; i++) {       // 从不同起点开始递归
        for (int j = 0; j < m; j++) {
            if (flag[i][j] && word[0] == board[i][j]) {
                dfs(result, board, flag, word, n, m, i, j, 0);
            }
        }
    }

    return result;
}

int P0079_WordSearch::test() {
    vector<vector<char>> board =
            {
                    {'A', 'B', 'C', 'E'},
                    {'S', 'F', 'C', 'S'},
                    {'A', 'D', 'E', 'E'}
            };

    cout << exist(board, "ABCCED") << endl;
    cout << exist(board, "ABCCEDFSA") << endl;
    cout << exist(board, "SEE") << endl;
    cout << exist(board, "ABCB") << endl;
    return 0;
}
