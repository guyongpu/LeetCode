//
// Created by yongpu on 2019/11/7 9:47.
//

#include "P0065_ValidNumber.h"

/**
 * 题目：有效数字
 * 描述：验证给定的字符串是否可以解释为十进制数字.
 * 思路：将字符串按照e进行分段，e前面为整数/小数，e后面为整数，然后分别判断是否有效.
 * 备注：要仔细处理.
 */

// 查询s中字符C的个数
int findNumOfC(string str, char c) {
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c) {
            cnt++;
        }
    }
    return cnt;
}

// 字符串str是否是有效的整数
bool isvaildInterger(string str) {
    if (str.length() == 0) {
        return false;
    }
    int index = 0;
    if (str[0] == '-' || str[0] == '+') {
        index++;
    }
    int len = str.length();
    bool flag_0 = true;
    for (int i = index; i < len; i++) {
        if (!('0' <= str[i] && str[i] <= '9')) {    //str中含有0-9和.之外的字符，返回false
            return false;
        }
        if ('0' <= str[i] && str[i] <= '9') {       //遇到0-9
            flag_0 = false;
        }
    }

    if (flag_0 == true) {       // 如果str中没有数字，如"+",则返回false
        return false;
    } else {
        return true;
    }
}

// 字符串str是否是有效的整数/小数
bool isvaildNum(string str) {
    if (findNumOfC(str, '.') > 1) {
        return false;
    }
    int index = 0;
    if (str[0] == '-' || str[0] == '+') {
        index++;
    }

    int len = str.length();
    int flag_0 = true;
    for (int i = index; i < len; i++) {
        if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '.')) { //str中含有0-9之外的字符，返回false
            return false;
        }
        if ('0' <= str[i] && str[i] <= '9') {   //遇到0-9
            flag_0 = false;
        }
    }

    if (flag_0 == true) {       // 如果str中没有数字，如"+",则返回false
        return false;
    } else {
        return true;
    }
}

// 检测字符串s是否被空格分为两个部分，如" 123 456"返回false,而" 23e-45  "返回true，s变为"23e-45"
bool detectSpace(string &s) {
    int start = 0;
    int end = 0;
    int len = s.length();
    bool flag = false;
    for (int i = 0; i < len; i++) {             //确定start
        if (s[i] != ' ') {
            start = i;
            flag = true;
            break;
        }
    }

    for (int i = len - 1; i >= 0; i--) {        //确定end
        if (s[i] != ' ') {
            end = i;
            flag = true;
            break;
        }
    }

    if (flag == false) {                        //全部都是空格
        return false;
    }

    for (int i = start; i <= end; i++) {        //检测start和end之间是否有空格
        if (s[i] == ' ') {
            return false;
        }
    }
    s = s.substr(start, end - start + 1);   // 截取start和end之间的字符串
    return true;
}

bool P0065_ValidNumber::isNumber(string s) {
    //将整数进行分段，以e为界限，e前面为整数/小数，e后面为整数
    int len = s.length();
    if (len == 0) {
        return false;
    }
    if (detectSpace(s) == false) {      // 检测空格是否将字符串分隔为两部分，并去空格
        return false;
    }

    if (s.find('e') != s.npos) {   // 存在e
        //提取e后面的部分
        int pos_e = s.find('e');
        string s_Sub1 = s.substr(0, pos_e);
        string s_Sub2 = s.substr(pos_e + 1, len - pos_e);
//        cout << "s_Sub1 = " << s_Sub1 << endl;
//        cout << "s_Sub2 = " << s_Sub2 << endl;

        //第一部分s_Sub1为整数/小数
        if (isvaildNum(s_Sub1) == false) {      //s_Sub1是否为有效整/小数即可
            return false;
        }
        //第二部分s_Sub2必须为整数
        if (isvaildInterger(s_Sub2) == false) { //s_Sub2是否为有效整数
            return false;
        }
    } else if (isvaildNum(s) == false) {    //不存在e，则只需要检查s是否为有效整/小数即可
        return false;
    }

    return true;
}

int P0065_ValidNumber::test() {
    cout << isNumber("   ") << endl;            //=> false  0
    cout << isNumber(" 1232  ") << endl;        //=> true   1
    cout << isNumber(" 12 32  ") << endl;       //=> false  0
    cout << isNumber("123e2erw3242") << endl;   //=> false  0
    cout << isNumber("0") << endl << endl;      // => true  1

    cout << isNumber(" 0.1 ") << endl;          // => true  1
    cout << isNumber("abc") << endl;            // => false 0
    cout << isNumber("1 a") << endl;            // => false 0
    cout << isNumber("2e10") << endl;           // => true  1
    cout << isNumber(" -90e3  ") << endl << endl;// => true  1

    cout << isNumber(" 1e") << endl;            // => false 0
    cout << isNumber("e3") << endl;             // => false 0
    cout << isNumber(" 6e-1") << endl;          // => true  1
    cout << isNumber(" 99e2.5 ") << endl;       // => false 0
    cout << isNumber("53.5e93") << endl << endl;// => true  1

    cout << isNumber(" --6 ") << endl;          // => false 0
    cout << isNumber("-+3") << endl;            // => false 0
    cout << isNumber("95a54e53") << endl;       // => false 0
    cout << isNumber("123") << endl;            // => true 1
    cout << isNumber(".") << endl << endl;      // => false 0

    cout << isNumber("+.") << endl;             // => false 0
    cout << isNumber("-") << endl;              // => false 0
    cout << isNumber("4e+") << endl;            // => false 0
    return 0;
}
