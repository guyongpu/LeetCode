//
// Created by yongpu on 2019/10/8.
//

#include "P0149_MaxPointsOnLine.h"

/**
 * 题目：直线上最多的点
 * 描述：给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上
 * 思路：对每个点进行计算通过第i个点的点的数量，对于每一个点，将斜率的分子分母约分后存储到map中
 * 备注：重合的点不用计算，直接+1就行.
 */

int P0149_MaxPointsOnLine::maxPoints(vector<vector<int>> &points) {
    if (points.size() <= 2)
        return points.size();
    int result = 0;
    int len = points.size();

    for (int i = 0; i < len; i++) { //遍历每个节点
        int poin_x = points[i][0];  //x坐标
        int poin_y = points[i][1];  //y坐标

        map<pair<int, int>, int> LineMap;
        int res_poin = 0;           //和第i个点在同一直线上的最大数目
        int cntMax = 0;

        //计算通过第i个点的最多的点数
        for (int j = i + 1; j < len; j++) {
            int x = poin_x - points[j][0];
            int y = poin_y - points[j][1];
            if (x == 0 && y == 0) {
                res_poin++;
                continue;
            }
            if (y < 0) {                //使y不为负数
                x = -x;
                y = abs(y);
            }

            int gcd_num = __gcd(x, y);  //找公约数
            if (gcd_num != 0) {         //不能除0
                x = x / gcd_num;
                y = y / gcd_num;
            }
            pair<int, int> tKey(x, y);  //斜率采用pair存储，防止精度问题溢出
            auto iter = LineMap.find(tKey);

            if (iter == LineMap.end()) {                      //已存在
                LineMap[tKey] = 1;            //将头部的 iter 赋值给 cache_map
            } else {
                LineMap[tKey]++;
            }
            cntMax = max(LineMap[tKey], cntMax);
        }
        res_poin = res_poin + cntMax + 1;   //加上本身的1
//        cout << i << ":" << res_poin << endl;
        result = max(result, res_poin);
    }
    return result;
}

int P0149_MaxPointsOnLine::test() {
    vector<int> p1 = {1, 1};
    vector<int> p2 = {3, 2};
    vector<int> p3 = {5, 3};
    vector<int> p4 = {4, 1};
    vector<int> p5 = {2, 3};
    vector<int> p6 = {1, 4};

    vector<vector<int>> points = {p1, p2, p3, p4, p5, p6};
    int result = maxPoints(points);
    cout << result << endl;

    return 0;
}
