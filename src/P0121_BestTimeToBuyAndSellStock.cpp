//
// Created by yongpu on 2019/11/1 13:36.
//

#include "P0121_BestTimeToBuyAndSellStock.h"

/**
 * 题目：买卖股票的最佳时机
 * 描述：给定一个数组，它的第i个元素是一支给定股票第i天的价格。如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 思路：方法1.遍历数组，记录当前为止的最小值，然后第二次遍历计算最大利益，也可以优化为一次遍历；方法2.暴力求解.
 * 备注：方法2接近动态规划思想.
 */

// 方法3.动态规划
int P0121_BestTimeToBuyAndSellStock::maxProfit_3(vector<int> &prices) {
    int len = prices.size();
    if (len <= 1) {
        return 0;
    }

    int iMax = len;
    int kMax = 3;
    int sMax = 2;

    vector<vector<vector<int>>> dp;
    for(int s = 0;s<sMax;s++){
        vector<vector<int>> kVec;
        for(int k = 0;k<kMax;k++){
            vector<int> sVec(sMax, 0);
            kVec.push_back(sVec);
        }
        dp.push_back(kVec);
    }

    cout << endl;
    cout << endl;
    cout << endl;

//    for(int i = 0 ;i< iMax;)

}

// 方法1.遍历记录当前最小值,接近动态规划思想
int P0121_BestTimeToBuyAndSellStock::maxProfit_1(vector<int> &prices) {
    int len = prices.size();
    if (len <= 1) {
        return 0;
    }
    int result = 0;
    vector<int> minVec(len, 0);
    minVec[0] = prices[0];
    for (int i = 1; i < len; i++) {
        minVec[i] = min(minVec[i - 1], prices[i]);
    }
    for (int i = 0; i < len; i++) {
        result = max(prices[i] - minVec[i], result);
    }
    return result;
}


// 方法2.暴力法
int P0121_BestTimeToBuyAndSellStock::maxProfit_2(vector<int> &prices) {
    int len = prices.size();
    int result = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (prices[j] > prices[i]) {
                result = max(result, prices[j] - prices[i]);
            }
        }
    }
    return result;
}

int P0121_BestTimeToBuyAndSellStock::test() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit_3(prices) << endl;
    return 0;
}
