//
// Created by yongpu on 2019/11/12 11:40.
//

#include "P0089_GrayCode.h"

/**
 * 题目：格雷编码
 * 描述：给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头.
 * 思路：从0开始，当flag = 1时，先添加1再加0，当flag=0时，先添加0再加1，进行递归.
 * 备注：递归实现
 *
 *             ---0
 *    ---0 ---|
 *    |        ---1
 * 0--|
 *    |       ----1
 *    ---1 ---|
 *            ----0
 */

void P0089_GrayCode::grayCode_Sub(vector<int> &result, int x, int flag, int times) {
    if (times == 0) {
        result.push_back(x);
    } else {
        if (flag == 0) {
            x = x << 1;
            grayCode_Sub(result, x, 0, times - 1);
            grayCode_Sub(result, x + 1, 1, times - 1);
        } else {
            x = x << 1;
            grayCode_Sub(result, x + 1, 0, times - 1);
            grayCode_Sub(result, x, 1, times - 1);
        }
    }
}

vector<int> P0089_GrayCode::grayCode(int n) {
    vector<int> result;
    if (n == 0) {
        result.push_back(0);
        return result;
    }
    grayCode_Sub(result, 0, 0, n);
    return result;
}

int P0089_GrayCode::test() {
    vector<int> result = grayCode(4);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}