//
// Created by yongpu on 2019/10/15 16:55.
//

#include "P0013_RomanToInteger.h"

/**
 * 题目：罗马数字转整数
 * 描述：给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内.
 * 思路：遍历字符串，2个字符的匹配优先1个字符，然后计算.
 * 备注：也可以使用哈希表
 */

int P0013_RomanToInteger::romanToInt(string s) {
    if (s.length() == 0)
        return 0;

    vector<string> romans = {"CM", "CD", "XC", "XL", "IX", "IV", "M", "D", "C", "L", "X", "V", "I"};
    vector<int> nums = {900, 400, 90, 40, 9, 4, 1000, 500, 100, 50, 10, 5, 1};

    int result = 0;
    int len = s.length();
    int index = 0;

    int pos = 0;
    while (pos < len) {
        string str;
        if (index <= 5)
            str = s.substr(pos, 2);
        else
            str = s.substr(pos, 1);

        if (str.find(romans[index]) != s.npos) {
            result = result + nums[index];
            pos = pos + romans[index].length();
        } else {
            index = 0;
            string str_temp;
            while (index < 13) {
                if (index <= 5)
                    str_temp = s.substr(pos, 2);
                else
                    str_temp = s.substr(pos, 1);

                if (str_temp.find(romans[index]) == s.npos) {
                    index++;
                } else {
                    break;
                }
            }
        }
    }
//    cout << result << endl;
    return result;
}

/**
int romanToInt(string s) {
    unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
    int r = m[s.substr(0, 1)];
    for(int i=1; i<s.size(); ++i){
        string two = s.substr(i-1, 2);
        string one = s.substr(i, 1);
        r += m[two] ? m[two] : m[one];
    }
    return r;
}
*/

int P0013_RomanToInteger::test() {
    cout << romanToInt("III") << endl;
    cout << romanToInt("IV") << endl;
    cout << romanToInt("IX") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIV") << endl;
    return 0;
}
