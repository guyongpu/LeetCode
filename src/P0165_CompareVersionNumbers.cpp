//
// Created by yongpu on 2019/10/13 13:27.
//

#include "P0165_CompareVersionNumbers.h"

/**
 * 题目：比较版本号
 * 描述：比较两个版本号 version1 和 version2.
 * 思路：切割出整数，然后比较.
 * 备注：常见题
 */

int P0165_CompareVersionNumbers::compareVersion(string version1, string version2) {
    vector<int> vers1, vers2;
    int len1 = version1.length();
    int len2 = version2.length();

    int start = 0;
    int last = 0;
    int num = 0;


    //处理version1
    start = 0;
    while (version1.find(".", start) != version1.npos) {
        int pos = version1.find(".", start);
        last = pos;
        num = atoi(version1.substr(start, last - start).c_str());
        start = pos + 1;
        vers1.push_back(num);
    }
    num = atoi(version1.substr(start, len1-start).c_str());
    vers1.push_back(num);

    //处理version2
    start = 0;
    while (version2.find(".", start) != version1.npos) {
        int pos = version2.find(".", start);
        last = pos;
        num = atoi(version2.substr(start, last - start).c_str());
        start = pos + 1;
        vers2.push_back(num);
    }
    num = atoi(version2.substr(start, len2-start).c_str());
    vers2.push_back(num);


    len1 = vers1.size();
    len2 = vers2.size();

    //开始比较
    int len = min(len1, len2);
    int result = 0;
    for (int i = 0; i < len; i++) {
        if (vers1[i] < vers2[i]) {
            result = -1;
            break;
        } else if (vers1[i] > vers2[i]) {
            result = 1;
            break;
        }
    }

    //如果version1与version2的个数不一样，且result等于0，则继续比较
    if (len1 != len2 && result == 0) {
        if (len1 > len2) {      //len1 更长
            for (int i = len2; i < len1; i++) {
                if (vers1[i] > 0) {
                    result = 1;
                }
            }
        } else {                //len2 更长
            for (int i = len1; i < len2; i++) {
                if (vers2[i] > 0) {
                    result = -1;
                }
            }
        }
    }
    return result;
}

int P0165_CompareVersionNumbers::test() {

    cout << compareVersion("1", "0") << endl;            //1
    cout << compareVersion("0", "0.0.0") << endl;        //0
    cout << compareVersion("0.1", "1.1") << endl;        //-1
    cout << compareVersion("1.0.1", "1") << endl;        //1
    cout << compareVersion("7.5.2.4", "7.5.3") << endl;  //-1
    cout << compareVersion("1.01", "1.001") << endl;     //0
    cout << compareVersion("1.0", "1.0.0") << endl;      //0
    return 0;
}
