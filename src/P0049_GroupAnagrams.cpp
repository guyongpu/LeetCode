//
// Created by yongpu on 2019/10/31 16:48.
//

#include "P0049_GroupAnagrams.h"

/**
 * 题目：字母异位词分组
 * 描述：给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串.
 * 思路：将每个字符串排序放到map<string,int>，int为result中的下标+1，如果重复出现，则放到result中
 * 备注：比较好做的题
 */

vector<vector<string>> P0049_GroupAnagrams::groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;
    int index = 0;
    unordered_map<string, int> strmap;

    for (int i = 0; i < strs.size(); i++) {
        string temp_str = strs[i];
        sort(temp_str.begin(), temp_str.end());
        if (strmap[temp_str] == 0) {    // 没出现过
            vector<string> vecstr;      // 新建一个vector
            vecstr.push_back(strs[i]);
            result.push_back(vecstr);
            index++;
            strmap[temp_str] = index;   // 将index+1存入strmap中，要+1，因为0表示未出现过
        } else {
            int index = strmap[temp_str];           // 获取index
            result[index - 1].push_back(strs[i]);   // index-1为result中的下标
        }
    }
    return result;
}

int P0049_GroupAnagrams::test() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
