//
// Created by yongpu on 2019/11/7 9:59.
//

#include "P0066_PlusOne.h"

/**
 * 题目：加一
 * 描述：给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一.
 * 思路：设置carry=1，sum = digits[i]+carry;当carry=0时直接终止，最后carry=1，则要在digits前插入1.
 * 备注：在digits原地上修改，空间复杂度O(1)
 */

vector<int> P0066_PlusOne::plusOne(vector<int> &digits) {
    if (digits.size() == 0) {
        return vector<int>(1, 1);
    }
    int len = digits.size();
    int sum = 0;
    int carry = 1;
    int i = len - 1;
    while (carry == 1 && i >= 0) {
        sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
        i--;
    }
    if (carry == 1) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int P0066_PlusOne::test() {
    vector<int> digits1 = {1, 2, 3};
    vector<int> digits2 = {9, 9, 9, 9};
    vector<int> digits3 = {9};
    vector<int> digits4 = {0};

    vector<int> result = plusOne(digits3);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}
