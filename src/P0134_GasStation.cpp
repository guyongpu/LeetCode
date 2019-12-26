//
// Created by yongpu on 2019/12/25 21:28.
//

#include "P0134_GasStation.h"

/**
 * 题目：加油站
 * 描述：在一条环路上有 N 个加油站，其中第 i 个加油站有汽油gas[i]升，如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1.
 * 思路：动态规划，1.找一个不可能为起点的点i；2.从start开始，填写dp；3.startvec中保存所有可能开始的起点；4.检查startvec中的每个点.
 * 备注：总的思路是找出所有可能开始的起点，然后检查，如果当前节点符合，且前一个也符合，则使用前一个的值，即dp[index] = dp[(index-1+num)%num].
 */

bool checkIndex(int start, vector<int> gas, vector<int> cost) {
    int gasNum = 0;
    int num = gas.size();
    int index;
    for (int i = start;; i++) {
        index = i % num;

        if (i > start && index == start) {
            return true;
        }

        gasNum = gasNum + gas[index];
        if (gasNum < cost[index]) {
            return false;
        }
        gasNum = gasNum - cost[index];
    }
}

int P0134_GasStation::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int num = gas.size();
    if (num == 0) {
        return -1;
    }
    vector<int> dp(num,-1);

    // 1.找一个不可能为起点的点i，令start = i
    int start = -1;
    for (int i = 0; i < num; i++) {
        if (gas[i] < cost[i]) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        return 0;   // 任意节点都可以满足要求
    }

    // 2.从start开始，填写dp
    // if (gas[index] < cost[index])  则dp[index] = -1;  表示index不可能为起点
    // if (gas[index] >= cost[index]) 如果dp[index]前一个dp不为-1，则dp[index]=前一个的值，否则为index
    for (int i = start; !(i > start && i % num == start); i++) {
        int index = i % num;
        if (gas[index] < cost[index]) {
            dp[index] = -1;
        } else {
            if (dp[(index - 1 +num) % num] != -1) {
                dp[index] = dp[(index - 1+num) % num];
            } else {
                dp[index] = index;
            }
        }
    }

    // 3.startvec中保存所有可能开始的起点
    vector<int> startvec;
    for (int i = 0; i < num; i++) {
        if (dp[i] != -1) {
            if (startvec.empty()) {
                startvec.push_back(dp[i]);
            } else {
                if (startvec.front() != dp[i]) {
                    startvec.push_back(dp[i]);
                }
            }
        }
    }

    //cout << "startvec size = " << startvec.size() << endl;

    // 4.检查startvec中的每个点
    for (int i = 0; i < startvec.size(); i++) {
        if (checkIndex(startvec[i], gas, cost)) {
            return startvec[i];
        }
    }

    // 未找到满足的则返回-1
    return -1;
}

int P0134_GasStation::test() {
    vector<int> gas = {3, 3, 4};
    vector<int> cost = {3, 4, 4};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
