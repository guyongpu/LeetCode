//
// Created by yongpu on 2019/11/15 21:09.
//

#include "P0093_RestoreIPAddresses.h"

/**
 * 题目：复原IP地址
 * 描述：给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式.
 * 思路：使用DFS递归方法，结束条件为index=size && times=4，即分为4段.
 * 备注：注意结束条件和剪枝.
 */

void P0093_RestoreIPAddresses::dfs(string s, int index, int times, int len, string temp, vector<string> &result) {
    if (index == s.size() && times == 4) {
        temp.erase(temp.end() - 1);
        result.push_back(temp);
    } else {
        if (times > 3) {        // 已经分为4段，则不能继续递归
            return;
        }
        for (int i = index; i < len; i++) {
            string s_sub = s.substr(index, i - index + 1);
            //  剪枝：s_sub的长度>3     s_sub的数字大于255      s_sub的长度大于1且首字符为0，如“002”
            if (s_sub.length() > 3 || stoi(s_sub) > 255 || (s_sub[0] == '0' && s_sub.length() > 1)) {
                break;
            }
            dfs(s, i + 1, times + 1, len, temp + s_sub + ".", result);
        }
    }
}

vector<string> P0093_RestoreIPAddresses::restoreIpAddresses(string s) {
    vector<string> result;
    string temp;
    dfs(s, 0, 0, s.length(), temp, result);
    return result;
}

int P0093_RestoreIPAddresses::test() {
    string s1 = "25525511135";
    string s2 = "0000";
    string s3 = "010010";
    vector<string> result = restoreIpAddresses(s2);
    int len = result.size();
    for (int i = 0; i < len; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
