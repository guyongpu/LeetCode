//
// Created by yongpu on 2019/11/6 9:10.
//

#include "P0051_N_Queens.h"

/**
 * 题目：N皇后
 * 描述：n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击.
 * 思路：采用数独的思想，使用map数组来记录是否行列存在重复，通过x+y和x-y的值记录斜率为1和-1，每次填写1列，尝试0->n-1行.
 * 备注：方法1为原始写法，方法2进行了优化和规范.
 */


// 方法2.将循环写在DFS函数里面，基本原理不变
/**
 * @param n  皇后的数量，即方框的大小
 * @return   得到的结果
 */
vector<vector<string>> P0051_N_Queens::solveNQueens_2(int n) {
    unordered_map<int, bool> rowMap(n);  //行
    unordered_map<int, bool> colMap(n);  //列
    unordered_map<int, bool> LineMap1;  //斜率为1
    unordered_map<int, bool> LineMap2;  //反斜率

    vector<vector<string>> result;

    string str(n, '.');
    vector<string> temp_ans(n, str);

    dfs_2(result, rowMap, colMap, LineMap1, LineMap2, temp_ans, n, 0, 0, 0);

    return result;
}

/**
 * @param result        保存结果
 * @param rowMap        每一行是否存放元素
 * @param colMap        每一列是否存放元素
 * @param LineMap1      斜率为1的情况，同一条斜率为1的线上(x+y)值相等
 * @param LineMap2      斜率为-1的情况，同一条斜率为-1的线上(x-y)值相等
 * @param temp_ans      临时结果，记录路径
 * @param n             边界大小
 * @param x             x坐标
 * @param y             y坐标
 * @param Qnum          已填的皇后数量
 */
void
P0051_N_Queens::dfs_2(vector<vector<string>> &result, unordered_map<int, bool> &rowMap,
                      unordered_map<int, bool> &colMap,
                      unordered_map<int, bool> &LineMap1, unordered_map<int, bool> &LineMap2,
                      vector<string> temp_ans, int n, int x, int y, int Qnum) {
    if (y == n) {
        result.push_back(temp_ans);
    } else {
        for (int i = 0; i < n; i++) {
            if (rowMap[i] == true) {
                continue;
            }
            if (rowMap[i] == false && LineMap1[i + y] == false &&
                LineMap2[i - y + (n - 1)] == false) { // 检查行、列、斜线
                LineMap1[i + y] = true;
                LineMap2[i - y + (n - 1)] = true;
                rowMap[i] = true;
                temp_ans[i][y] = 'Q';
                Qnum++;

                dfs_2(result, rowMap, colMap, LineMap1, LineMap2, temp_ans, n, i, y + 1, Qnum);

                LineMap1[i + y] = false;
                LineMap2[i - y + (n - 1)] = false;
                rowMap[i] = false;
                temp_ans[i][y] = '.';
                Qnum--;
            }
        }
    }
}

/*************************************************************************/

// 方法1
vector<vector<string>> P0051_N_Queens::solveNQueens_1(int n) {
    unordered_map<int, bool> rowMap(n);  //行
    unordered_map<int, bool> colMap(n);  //列
    unordered_map<int, bool> LineMap1;  //斜率为1
    unordered_map<int, bool> LineMap2;  //反斜率

    vector<vector<string>> result;

    string str(n, '.');
    vector<string> temp_ans(n, str);

    for (int i = 0; i < n; i++) {
        //dfs_1_1(result, rowMap, colMap, LineMap1, LineMap2, temp_ans, n, i, 0, 0);
        dfs_1_2(result, rowMap, colMap, LineMap1, LineMap2, temp_ans, n, i, 0, 0);
    }

    return result;
}


/**
 * 最原始的DFS函数
 * @param result        保存结果
 * @param rowMap        每一行是否存放元素
 * @param colMap        每一列是否存放元素
 * @param LineMap1      斜率为1的情况，同一条斜率为1的线上(x+y)值相等
 * @param LineMap2      斜率为-1的情况，同一条斜率为-1的线上(x-y)值相等
 * @param temp_ans      临时结果，记录路径
 * @param n             边界大小
 * @param x             x坐标
 * @param y             y坐标
 * @param Qnum          已填的皇后数量
 */
void
P0051_N_Queens::dfs_1_1(vector<vector<string>> &result, unordered_map<int, bool> &rowMap,
                        unordered_map<int, bool> &colMap,
                        unordered_map<int, bool> &LineMap1, unordered_map<int, bool> &LineMap2,
                        vector<string> temp_ans, int n, int x, int y, int Qnum) {
    rowMap[x] = true;
    colMap[y] = true;
    LineMap1[x + y] = true;
    LineMap2[x - y + (n - 1)] = true;
    temp_ans[x][y] = 'Q';
    Qnum++;

    if (Qnum == n) {
        result.push_back(temp_ans);
    } else {
        for (int i = 0; i < n; i++) {
            int j = y + 1;
            for (int j = y; j < n; j++) {
                if (rowMap[i] == false && colMap[j] == false && LineMap1[i + j] == false &&
                    LineMap2[i - j + (n - 1)] == false) { // 检查行、列、斜线
                    dfs_1_1(result, rowMap, colMap, LineMap1, LineMap2, temp_ans, n, i, j, Qnum);
                }
            }
        }
    }
    LineMap1[x + y] = false;
    LineMap2[x - y + (n - 1)] = false;
    rowMap[x] = false;
    colMap[y] = false;
}

/**
 * 相对DFS_1_1化简后
 * @param result        保存结果
 * @param rowMap        每一行是否存放元素
 * @param colMap        每一列是否存放元素
 * @param LineMap1      斜率为1的情况，同一条斜率为1的线上(x+y)值相等
 * @param LineMap2      斜率为-1的情况，同一条斜率为-1的线上(x-y)值相等
 * @param temp_ans      临时结果，记录路径
 * @param n             边界大小
 * @param x             x坐标
 * @param y             y坐标
 * @param Qnum          已填的皇后数量
 */
void
P0051_N_Queens::dfs_1_2(vector<vector<string>> &result, unordered_map<int, bool> &rowMap,
                        unordered_map<int, bool> &colMap,
                        unordered_map<int, bool> &LineMap1, unordered_map<int, bool> &LineMap2,
                        vector<string> temp_ans, int n, int x, int y, int Qnum) {
    rowMap[x] = true;
    LineMap1[x + y] = true;
    LineMap2[x - y + (n - 1)] = true;
    temp_ans[x][y] = 'Q';
    Qnum++;

    if (Qnum == n) {
        result.push_back(temp_ans);
    } else {
        for (int i = 0; i < n; i++) {
            if (rowMap[i] == true) {
                continue;
            }
            int j = y + 1;
            if (j < n) {
                if (LineMap1[i + j] == false &&
                    LineMap2[i - j + (n - 1)] == false) { // 检查行、列、斜线
                    dfs_1_2(result, rowMap, colMap, LineMap1, LineMap2, temp_ans, n, i, j, Qnum);
                }
            }
        }
    }
    LineMap1[x + y] = false;
    LineMap2[x - y + (n - 1)] = false;
    rowMap[x] = false;
    temp_ans[x][y] = '.';
}


int P0051_N_Queens::test() {
    vector<vector<string>> result = solveNQueens_2(4);

    cout << "result.size() = " << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
