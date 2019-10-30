//
// Created by yongpu on 2019/10/26 9:43.
//

#include "P0040_CombinationSumII.h"

/**
 * 题目：组合总和II
 * 描述：给定一个数组candidates 和一个目标数 target ，找出candidates中所有可以使数字和为 target 的组合，每个组合中每个数字只用一次.
 * 思路：在P0039的基础上，加上两个去重条件，(1)在从start开始时，如果candidates[i-1] = candidates[i]，则不进行计算;（2）下一次从i+1开始.
 * 备注：也可以使用hashmap实现.
 */

vector<vector<int>> P0040_CombinationSumII::combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> record;
    map<vector<int>, int> resultMap;

    sort(candidates.begin(), candidates.end());
    DFS_combinationSum2(result, resultMap, candidates, record, target, 0);
    return result;
}

void
P0040_CombinationSumII::DFS_combinationSum2(vector<vector<int>> &result, map<vector<int>, int> &resultMap,
                                            vector<int> &candidates, vector<int> record,
                                            int target, int start) {
    if (target == 0) {
//        if (resultMap[record] == 0) {
            result.push_back(record);
//            resultMap[record] = 1;
//        }
    } else {
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i - 1] == candidates[i])        //去重的关键1
                continue;
            if (target >= candidates[i]) {
                record.push_back(candidates[i]);
                DFS_combinationSum2(result, resultMap,candidates, record, target - candidates[i], i + 1);//去重的关键2
                record.pop_back();
            }
        }

    }
}

int P0040_CombinationSumII::test() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

    vector<vector<int>> result = combinationSum2(candidates, 8);

    int resNum = result.size();
    for (int i = 0; i < resNum; i++) {
        int Num = result[i].size();
        for (int j = 0; j < Num; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
