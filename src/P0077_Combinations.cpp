//
// Created by yongpu on 2019/11/10 11:10.
//

#include "P0077_Combinations.h"

/**
 * 题目：组合
 * 描述：给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合.
 * 思路：使用dfs实现，每次添加一个数i，下一次从i+1开始，但需要进行剪枝，否则时间复杂度较高.
 * 备注：理解剪枝方法.
 */


void dfs(vector<vector<int>> &result, vector<int> path, int curr, int n, int k, int &cnt) {
    cnt++;                                          // 用于记录递归的次数，调试变量
    if (path.size() == k) {
        result.push_back(path);
    } else {
        for (int i = curr; i <= n; i++) {
            if (n - i + 1 >= k - path.size()) {     // 剪枝，k-path.size表示还需要的元素个数；n - i + 1 表示目前可以选择的元素个数
            // if(1){ //不剪枝的情况
                path.push_back(i);
                dfs(result, path, i + 1, n, k, cnt);
                path.pop_back();
            }
        }
    }
}

vector<vector<int>> P0077_Combinations::combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    int cnt = 0;
    dfs(result, path, 1, n, k, cnt);
    cout << "cnt= " << cnt << endl;
    return result;
}

int P0077_Combinations::test() {
    vector<vector<int>> result = combine(5, 3);
    int len = result.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
