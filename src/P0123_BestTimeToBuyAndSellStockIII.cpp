//
// Created by yongpu on 2019/11/1 15:32.
//

#include "P0123_BestTimeToBuyAndSellStockIII.h"
/**
 * 题目：买卖股票的最佳时机III
 * 描述：给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易.
 * 思路：方法1：遍历一次，记录minLeft和maxRight，然后遍历更新result；方法2：先暴力法确定两个点，然后再遍历剩余数据；方法3:暴力法解决
 * 备注：掌握方法1、2、3
 */

// 方法1.一次遍历实现
int P0123_BestTimeToBuyAndSellStockIII::maxProfit_1(vector<int> &prices) {
    int len = prices.size();
    if (len <= 1) {
        return 0;
    }

    vector<int> minLeft(len, 0);        // 记录从左往右当前位置的最小值，用于计算[0,i]的最大收益
    vector<int> maxRight(len, 0);       // 记录从右往左当前位置的最大值，用于计算[i+1,len-1]的最大收益

    minLeft[0] = prices[0];
    maxRight[len - 1] = prices[len - 1];
    for (int i = 1; i < len; i++) {
        minLeft[i] = min(minLeft[i - 1], prices[i]);
        maxRight[len - 1 - i] = max(maxRight[len - 1 - i + 1], prices[len - 1 - i]);
    }
    //{3,3,5,0,0,3,1,4};
    int result = 0;
    int profit1 = 0;
    int profit2 = 0;
    for (int i = 0; i < len; i++) {
        profit1 = max(profit1, prices[i]-minLeft[i]);    //[0,i]，profit记录从[0,i]的最大值
        if (i + 1 < len) {
            profit2 = max(0, maxRight[i + 1] - prices[i + 1]);    //[i+1,len-1]，profit2每次更新，总有一个时刻会对应最大值
        }
        result = max(result, profit1 + profit2);        // 记录最大收益
    }
    return result;

}

// 方法2.直接暴力法确定2个点，然后剩下的再遍历解决
int P0123_BestTimeToBuyAndSellStockIII::maxProfit_2(vector<int> &prices) {
    int len = prices.size();
    int maxProfit = 0;

    vector<int> dif(len, 0);
    for (int i = 1; i < len; i++) {
        dif[i] = prices[i] - prices[i - 1];
    }

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (prices[j] <= prices[i]) {
                continue;
            }
            int profit1 = prices[j] - prices[i];         //[i,j]
            maxProfit = max(maxProfit, profit1);

            int profit2 = 0;    //[j+1,len]
            int minPrice = INT_MAX;
            for (int k = j + 1; k < len; k++) {
                minPrice = min(minPrice, prices[k]);
                if (prices[k] > minPrice) {
                    profit2 = max(profit2, prices[k] - minPrice);
                }
            }
            int tempProfit = profit1 + profit2;
            maxProfit = max(maxProfit, tempProfit);
        }
    }
    return maxProfit;
}

// 方法3.直接暴力法确定4个点
int P0123_BestTimeToBuyAndSellStockIII::maxProfit_3(vector<int> &prices) {
    int len = prices.size();
    int maxProfit = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (prices[j] < prices[i]) {
                continue;
            }
            int profit1 = prices[j] - prices[i];            //[i,j]

            maxProfit = max(maxProfit, profit1);
            for (int k = j + 1; k < len; k++) {
                for (int z = k + 1; z < len; z++) {
                    if (prices[z] < prices[k]) {
                        continue;
                    }
                    int tempProfit = 0;
                    int profit2 = prices[z] - prices[k];    //[k,z]

                    tempProfit = profit1 + profit2;
                    maxProfit = max(maxProfit, tempProfit);
                }
            }
        }
    }
    return maxProfit;
}

int P0123_BestTimeToBuyAndSellStockIII::test() {
    vector<int> prices1 = {1, 2, 3, 4, 6, 3, 3, 5, 0, 0, 3, 1, 4, 9, 7};
    vector<int> prices2 = {1, 2, 3, 4, 5};
    vector<int> prices3 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit_1(prices3) << endl;
    return 0;
}
