//
// Created by yongpu on 2019/10/15 10:39.
//

#include "P0007_ReverseInteger.h"

/**
 * 题目：整数反转
 * 描述：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转.
 * 思路：法1：int->string->反转->long long int->溢出判断->int; 法2：常规方法做，每次判断溢出.
 * 备注：两个方法要掌握.
 */

int P0007_ReverseInteger::reverse_1(int x) {
    string str = to_string(x);
    if (x < 0) {
        std::reverse(str.begin() + 1, str.end());
    } else {
        std::reverse(str.begin(), str.end());
    }

//    cout << str<<endl;
    long long int xl = atoll(str.c_str());

    int result = 0;
    if (xl < INT_MIN || xl > INT_MAX) {
        result = 0;
    } else {
        result = (int) xl;
    }

    return result;
}


/**
 * 从ans * 10 + pop > MAX_VALUE这个溢出条件来看
 *      当出现 ans > MAX_VALUE / 10 且 还有pop需要添加 时，则一定溢出
 *      当出现 ans == MAX_VALUE / 10 且 pop > 7 时，则一定溢出，7是2^31 - 1的个位数
 * 从ans * 10 + pop < MIN_VALUE这个溢出条件来看
 *      当出现 ans < MIN_VALUE / 10 且 还有pop需要添加 时，则一定溢出
 *      当出现 ans == MIN_VALUE / 10 且 pop < -8 时，则一定溢出，8是-2^31的个位数
 */
int P0007_ReverseInteger::reverse_2(int x) {
    int ans = 0;
    while (x != 0) {
        int pop = x % 10;
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7))
            return 0;
        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8))
            return 0;
        ans = ans * 10 + pop;
        x = x / 10;
    }
    return ans;
}

int P0007_ReverseInteger::test() {
    cout << reverse_1(0) << endl;
    cout << reverse_2(0) << endl;
    cout << reverse_1(-123) << endl;
    cout << reverse_2(-123) << endl;
    cout << reverse_1(123) << endl;
    cout << reverse_2(123) << endl;
    cout << reverse_1(2147483647) << endl;
    cout << reverse_2(2147483647) << endl;

    return 0;
}
