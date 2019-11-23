//
// Created by yongpu on 2019/11/23 21:42.
//

#include "P0120_Triangle.h"

void dfs(vector<vector<int>> &triangle, int pos_i, int pos_j, int temp, int &result) {
    if (pos_i == triangle.size()) {
        result = min(result, temp);
    } else {

    }


}

int P0120_Triangle::minimumTotal(vector<vector<int>> &triangle) {
    int result = INT_MAX;

    dfs(triangle, 0, 0, 0, result);

    return 0;
}

int P0120_Triangle::test() {
    vector<vector<int>> triangle = {
            {2},
            {3, 4},
            {6, 5, 8},
            {4, 1, 8, 3},
    };

    cout << minimumTotal(triangle) << endl;

    return 0;
}
