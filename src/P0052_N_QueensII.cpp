//
// Created by yongpu on 2019/11/6 11:41.
//

#include "P0052_N_QueensII.h"

int P0052_N_QueensII::totalNQueens(int n) {
    unordered_map<int, bool> rowMap(n);  //行
    unordered_map<int, bool> colMap(n);  //列
    unordered_map<int, bool> LineMap1;  //正斜率
    unordered_map<int, bool> LineMap2;  //反斜率

    int result = 0;


    for (int i = 0; i < n; i++) {
        dfs(result, rowMap, colMap, LineMap1, LineMap2, n, i, 0, 0);
    }

    return result;
}

void P0052_N_QueensII::dfs(int &result, unordered_map<int, bool> &rowMap,
                           unordered_map<int, bool> &colMap, unordered_map<int, bool> &LineMap1,
                           unordered_map<int, bool> &LineMap2, int n, int x, int y, int Qnum) {
    rowMap[x] = true;
    colMap[y] = true;
    LineMap1[x + y] = true;
    LineMap2[x - y + (n - 1)] = true;
    Qnum++;

    if (Qnum == n) {
        result++;
    } else {
        for (int i = 0; i < n; i++) {
            if (rowMap[i] == true) {
                continue;
            }
            int j = y + 1;
            if (j < n) {
                if (LineMap1[i + j] == false &&
                    LineMap2[i - j + (n - 1)] == false) { // 检查行、列、斜线
                    dfs(result, rowMap, colMap, LineMap1, LineMap2, n, i, j, Qnum);
                }
            }
        }
    }
    LineMap1[x + y] = false;
    LineMap2[x - y + (n - 1)] = false;
    rowMap[x] = false;
    colMap[y] = false;
}

int P0052_N_QueensII::test() {
    cout << totalNQueens(4) << endl;
    return 0;
}
