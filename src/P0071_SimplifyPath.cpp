//
// Created by yongpu on 2019/11/8 15:29.
//

#include "P0071_SimplifyPath.h"

/**
 * 题目：简化路径
 * 描述：以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径.
 * 思路：先根据/分隔字符，然后遍历，遇到.回退1；遇到..，回退2。最后拼接路径即可.
 * 备注：用vector删除效率较低，用stack会好一些.
 */

string P0071_SimplifyPath::simplifyPath(string path) {
    int len = path.length();
    if (len <= 1) {
        return path;
    }
    // 按照/分隔path
    vector<string> pathVec = {"/"};
    for (int i = 1; i < len; i++) {
        if (path[i] != '/') {
            int pos1 = i;
            i++;
            while (path[i] != '/' && i != len) {
                i++;
            }
            int pos2 = i;
            string file = path.substr(pos1, pos2 - pos1);
//            cout << file << endl;
            pathVec.push_back(file);
        }
    }

    // 遍历pathVec
    auto iter = pathVec.begin() + 1;

    while (iter != pathVec.end()) {
        string str = *iter;
//        cout << str << endl;
        if (str == ".") {                   //删除.，回退1
            pathVec.erase(iter);
            iter--;
        } else if (str == "..") {           //删除..，回退2
            pathVec.erase(iter);
            iter--;
            if (iter != pathVec.begin()) {  // 已经是根目录，则不继续回退
                pathVec.erase(iter);
                iter--;
            }
        } else {                            // 正常目录，则继续遍历
            iter++;
        }
    }
    string result;
    if (pathVec.size() == 1) {              // 只有根目录
        result = "/";
    } else {                                // 拼接
        for (int i = 1; i < pathVec.size(); i++) {
            result = result + "/" + pathVec[i];
        }
    }

    return result;
}

int P0071_SimplifyPath::test() {
    vector<string> testVec;
    testVec.push_back("/");
    testVec.push_back("/../../../../");
    testVec.push_back("/home//foo/.//aa/bb/cc/dd/ee");
    testVec.push_back("//////./");
    testVec.push_back("/a/../../b/../c//.//");
    testVec.push_back("/home/");
    testVec.push_back("/../");
    testVec.push_back("/home/foo/");
    testVec.push_back("/a/./b/../../c/");
    testVec.push_back("/a/../../b/../c//.//");
    testVec.push_back("/a//b////c/d//././/..");

    for (int i = 0; i < testVec.size(); i++) {
        cout << simplifyPath(testVec[i]) << endl;
    }
    return 0;
}
