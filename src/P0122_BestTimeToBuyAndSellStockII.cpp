//
// Created by yongpu on 2019/11/1 15:00.
//

#include "P0122_BestTimeToBuyAndSellStockII.h"

/**
 * 题目：买卖股票的最佳时机II
 * 描述：给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格.设计一个算法来计算你所能获取的最大利润.
 * 思路：计算差值，将所有差值为正表示能够获得收益，加差值为正的值累加.
 * 备注：其实也可以优化为一次遍历.
 */

int P0122_BestTimeToBuyAndSellStockII::maxProfit(vector<int> &prices) {
    int len = prices.size();
    if (len <= 1) {
        return 0;
    }
    vector<int> dif(len, 0);
    for (int i = 1; i < len; i++) {
        dif[i] = prices[i] - prices[i - 1];
    }
    int result = 0;
    for (int i = 0; i < len; i++) {
        if(dif[i]>0){
            result = result + dif[i];
        }
    }
    return result;
}

int P0122_BestTimeToBuyAndSellStockII::test() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {1,2,3,4,5,6};
    cout << maxProfit(prices2) << endl;
    return 0;
}
