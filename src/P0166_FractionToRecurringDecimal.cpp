//
// Created by yongpu on 2019/10/13 21:19.
//

#include "P0166_FractionToRecurringDecimal.h"

/**
 * 题目：分数到小数
 * 描述：给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。如果小数部分为循环小数，则将循环的部分括在括号内.
 * 思路：先计算整数部分，然后将每次的被除数保存，知道出现重复，则说明找到循环节[pos,strNum.size-1]，否则是有限小数.
 * 备注：分数的小数部分一定是有限或者循环的.
 */

string P0166_FractionToRecurringDecimal::fractionToDecimal(int numerator, int denominator) {
    string result;
    if (denominator == 0)
        return result;

    //统一符号位
    if ((numerator == 0) || (numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0)) {
        result = result;
    } else {
        result = result + "-";
    }
    //转化为正数计算
    long long numerator_l = abs((long long)numerator);
    long long denominator_l = abs((long long)denominator);

    long long int num1 = numerator_l / denominator_l; //整数部分
    result = result + to_string(num1);  //存入结果中

    long long int num2 = numerator_l % denominator_l; //余数部分

    vector<int> vecNum;
    vector<int> strNum;     //小数部分
    int pos = 0;
    bool flag = false;      //是否循环小数

    if (num2 != 0) {        //是否存在余数
        result = result + ".";

        vecNum.push_back(num2);
        while (num2) {
//            cout << "--" << num2 << endl;
            int temp = num2 * 10 / denominator_l;
            strNum.push_back(temp);     //结果存入到strNum中

            num2 = num2 * 10 - denominator_l * temp;
            if (find(vecNum.begin(), vecNum.end(), num2) == vecNum.end()) {     //是否出现重复
                vecNum.push_back(num2);
            } else {
                pos = find(vecNum.begin(), vecNum.end(), num2) - vecNum.begin();
                flag = true;
//                cout<< vecNum.size() << endl;
//                cout << "pos= " << pos << "   " << "num2 = " << num2 << "  strNum size=" << strNum.size()<< endl;
                break;      //如果重复则结束，说明找到循环节index，循环部分为[pos,strNum.size-1]
            }
        }

        if (flag == true) {     //循环小数
            // strNum中小数部分，[0，pos-1]
            for (int i = 0; i < pos; i++) {
                result = result + to_string(strNum[i]);
            }
            // strNum中循环节部分，[pos,strNum.size-1]
            result = result + "(";
            for (int i = pos; i < strNum.size(); i++) {
                result = result + to_string(strNum[i]);
            }
            result = result + ")";
        } else {                //有限小数
            for (int i = 0; i < strNum.size(); i++) {
                result = result + to_string(strNum[i]);
            }
        }
    }

    return result;
}

int P0166_FractionToRecurringDecimal::test() {
    cout << fractionToDecimal(1, 25) << endl;
    cout << fractionToDecimal(-1, -2147483648) << endl;     //0.0000000004656612873077392578125
    cout << fractionToDecimal(1, -2147483648) << endl;     //-0.0000000004656612873077392578125
    cout << fractionToDecimal(-2147483648, -1) << endl;     //2147483648
    cout << fractionToDecimal(0, -1) << endl;     //2147483648
    cout << fractionToDecimal(0, 1) << endl;     //2147483648
    return 0;
}
