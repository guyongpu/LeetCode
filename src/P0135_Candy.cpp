//
// Created by yongpu on 2019/12/26 10:39.
//

#include "P0135_Candy.h"

/**
 * 题目：分发糖果
 * 描述：老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分.
 * 思路：两次扫描，从左往右，再从右往左，要求符合左右规则.
 * 备注：掌握两次扫描方法
 */

int P0135_Candy::candy_1(vector<int> &ratings) {
    int num = ratings.size();
    vector<int> candyNum(num, 1);

    for (int i = 0; i < num; i++) {
        if (i + 1 < num && ratings[i] > ratings[i + 1]) {
            if (candyNum[i] <= candyNum[i + 1]) {
                candyNum[i]++;
            }
            // 往左回溯
            for (int j = i; j > 0; j--) {
                if (j - 1 >= 0 && ratings[j - 1] > ratings[j]) {
                    if (candyNum[j - 1] <= candyNum[j]) {
                        candyNum[j - 1]++;
                    }
                } else {
                    break;
                }
            }
        }
        if (i - 1 >= 0 && ratings[i - 1] < ratings[i]) {
            if (candyNum[i - 1] >= candyNum[i]) {
                candyNum[i]++;
            }
            // 往右回溯
            for (int j = i; j < num; j++) {
                if (j + 1 < num && ratings[j] < ratings[j + 1]) {
                    if (candyNum[j] >= candyNum[j + 1]) {
                        candyNum[j + 1]++;
                    }
                } else {
                    break;
                }
            }
        }

    }


    int sum = accumulate(candyNum.begin(), candyNum.end(), 0);
    return sum;
}

/**
 * 两次扫描
 *
 * 先从左至右遍历学生成绩 ratings，按照以下规则给糖，并记录在 left 中：
 * 先给所有学生 11 颗糖；
 * 若ratings[i]>ratings[i−1] ，则第 ii 名学生糖比第 i - 1i−1 名学生多 11 个。
 * 若ratings[i]<=ratings[i−1],，则第 ii 名学生糖数量不变。（交由从右向左遍历时处理。）
 * 经过此规则分配后，可以保证所有学生糖数量 满足左规则 。
 * 同理，在此规则下从右至左遍历学生成绩并记录在 right 中，可以保证所有学生糖数量 满足右规则 。
 * 最终，取以上 22 轮遍历 left 和 right 对应学生糖果数的 最大值 ，这样则 同时满足左规则和右规则 ，即得到每个同学的最少糖果数量。
 */
int P0135_Candy::candy_2(vector<int> &ratings) {
    int num = ratings.size();
    vector<int> candies(num, 1);
    for (int i = 1; i < num; i++) {
        if (ratings[i - 1] < ratings[i]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = num - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    int sum = accumulate(candies.begin(), candies.end(), 0);
    return sum;
}


int P0135_Candy::test() {
    vector<int> ratings1 = {1, 0, 2};
    cout << candy_2(ratings1) << endl;

    vector<int> ratings2 = {1, 2, 2};
    cout << candy_2(ratings2) << endl;
    return 0;
}

