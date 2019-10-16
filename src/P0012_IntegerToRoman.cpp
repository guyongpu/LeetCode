//
// Created by yongpu on 2019/10/15 15:34.
//

#include "P0012_IntegerToRoman.h"

/**
 * 题目：整数转罗马数字
 * 描述：给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内.
 * 思路：法1：常规做法；法2：贪心算法
 * 备注：掌握两种做法.
 */

string P0012_IntegerToRoman::intToRoman_1(int num) {
    string result;

    if (num < 1 || num > 3999)
        return result;

    int len = 0;
    int copy_num = num;
    while (copy_num) {
        copy_num = copy_num / 10;
        len++;
    }

    copy_num = num;
    for (int i = 0; i < len; i++) {
        int n = copy_num / pow(10, len - 1 - i);
        copy_num = copy_num % (int) pow(10, len - 1 - i);

        int temp = n * pow(10, len - 1 - i);

        if (temp >= 1000) {
            for (int j = 0; j < n; j++) {
                result.push_back('M');
            }
        } else if (temp >= 900) {
            result.push_back('C');
            result.push_back('M');
        } else if (temp >= 500) {
            result.push_back('D');

            int dif = temp - 500;
            int m = dif / 100;
            for (int j = 0; j < m; j++) {
                result.push_back('C');
            }
        } else if (temp >= 400) {
            result.push_back('C');
            result.push_back('D');
        } else if (temp >= 100) {
            int m = temp / 100;
            for (int j = 0; j < m; j++) {
                result.push_back('C');
            }
        } else if (temp >= 90) {
            result.push_back('X');
            result.push_back('C');
        } else if (temp >= 50) {
            result.push_back('L');

            int dif = temp - 50;
            int m = dif / 10;
            for (int j = 0; j < m; j++) {
                result.push_back('X');
            }
        } else if (temp >= 40) {
            result.push_back('X');
            result.push_back('L');
        } else if (temp >= 10) {
            int m = temp / 10;
            for (int j = 0; j < m; j++) {
                result.push_back('X');
            }
        } else if (temp >= 9) {
            result.push_back('I');
            result.push_back('X');
        } else if (temp >= 5) {
            result.push_back('V');

            int dif = temp - 5;
            int m = dif / 1;
            for (int j = 0; j < m; j++) {
                result.push_back('I');
            }
        } else if (temp >= 4) {
            result.push_back('I');
            result.push_back('V');
        } else if (temp >= 1) {
            int m = temp / 1;
            for (int j = 0; j < m; j++) {
                result.push_back('I');
            }
        } else { ;
        }
    }
    return result;
}

string P0012_IntegerToRoman::intToRoman_2(int num) {
    // 把阿拉伯数字与罗马数字可能出现的所有情况和对应关系，放在两个数组中
    // 并且按照阿拉伯数字的大小降序排列，这是贪心选择思想
    vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int index = 0;
    for (int i = 12; i >= 0; i--) {
        if (num >= nums[i]) {
            index = i;
            continue;
        }else{
            break;
        }
    }

    string result;
    while (num >= nums[index]) {
        result = result + romans[index];
        num = num - nums[index];

        if (num >= nums[index]) {   //不需要更改index
            continue;
        } else {                    //更改index
            for (int i = index; i < 13; i++) {
                if (num >= nums[i]) {
                    index = i;
                    break;
                }
            }
        }
    }
    return result;

}

int P0012_IntegerToRoman::test() {

    cout << intToRoman_1(600) << endl;
    cout << intToRoman_2(600) << endl;
    cout << intToRoman_1(3) << endl;
    cout << intToRoman_2(3) << endl;
    cout << intToRoman_1(4) << endl;
    cout << intToRoman_2(4) << endl;
    cout << intToRoman_1(9) << endl;
    cout << intToRoman_2(9) << endl;
    cout << intToRoman_1(58) << endl;
    cout << intToRoman_2(58) << endl;
    cout << intToRoman_1(1994) << endl;
    cout << intToRoman_2(1994) << endl;
    cout << intToRoman_1(3999) << endl;
    cout << intToRoman_2(3999) << endl;
    return 0;
}
