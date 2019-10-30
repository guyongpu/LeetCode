//
// Created by yongpu on 2019/10/26 9:12.
//

#include "P0039_CombinationSum.h"

/**
 * 题目：组合总和
 * 描述：给定一个无重复元素的数组 candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合，数字可以重复出现.
 * 思路：采用DFS做，记录路径record，符合要求时将record加入result中，然后继续DFS.
 * 备注：重要题，掌握DFS.
 */

vector<vector<int>> P0039_CombinationSum::combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;     //保存最终结果
    vector<int> record;             //记录路径
    DFS_combinationSum(result, candidates, record, target, 0);
    return result;
}

void
P0039_CombinationSum::DFS_combinationSum(vector<vector<int>> &result, vector<int> &candidates, vector<int> record,
                                         int target, int start) {
    if (target == 0) {                  //当target=0，则说明符合要求
        result.push_back(record);
    } else {
        for (int i = start; i < candidates.size(); i++)         //从start开始，便于剪枝和避免重复结果
            if (target >= candidates[i]) {
                record.push_back(candidates[i]);                //record中加入candidates[i]
                DFS_combinationSum(result, candidates, record, target - candidates[i], i);  //继续DFS
                record.pop_back();                              //从record中弹出candidates[i]
            }
    }
}

int P0039_CombinationSum::test() {
    vector<int> candidates = {2, 3, 5};
    vector<vector<int>> result = combinationSum(candidates, 8);

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
