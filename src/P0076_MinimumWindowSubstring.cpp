//
// Created by yongpu on 2019/11/10 9:57.
//

#include "P0076_MinimumWindowSubstring.h"

/**
 * 题目：最小覆盖字串
 * 描述：给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串.
 * 思路：用3个map，map_win，map_t，map_s,使用滑动窗口做法，end用于扩展，start用于缩小窗口.
 * 备注：滑动窗口.
 */

string P0076_MinimumWindowSubstring::minWindow(string s, string t) {
    int len_s = s.length();
    int len_t = t.length();
    if (len_s == 0 || len_s < len_t) {
        return string("");
    }
    if (s.find(t) != s.npos) {
        return t;
    }
    unordered_map<char, int> map_win;       // 记录当前滑动窗口字符的出现次数
    unordered_map<char, int> map_t;         // t中各个字符出现的情况
    unordered_map<char, int> map_cmp;       // 用于与map_t进行比较，map_cmp中最大次数不超过map_t

    // 构造map_t
    for (int i = 0; i < len_t; i++) {
        map_t[t[i]]++;
    }

    int start = 0;              // 滑动窗口起点
    int end = 0;                // 滑动窗口终点
    string result;              // 所求字符串
    int minLen = INT_MAX;       // result的长度
    while (end < len_s) {
        char cend = s[end];
        if (map_t.find(cend) != map_t.end()) {      // t中包含c，即s[end]
            map_win[cend]++;                        // map_win累加
            if (map_win[cend] >= map_t[cend]) {     // map_cmp最大次数不超过map_t
                map_cmp[cend] = map_t[cend];
            }
        }
        if (map_cmp == map_t) {                     // 窗口以满足条件，则开始缩小
            // 开始缩小窗口
            while (map_cmp == map_t) {
                if (minLen > (end - start + 1)) {   // 更新result和minLen
                    result = s.substr(start, end - start + 1);
                    minLen = end - start + 1;
                }
                char cstart = s[start];
                if (map_t.find(cstart) != map_t.end()) {    // s[start]不在t中，则无需更新map_win
                    map_win[cstart]--;
                    if (map_win[cstart] >= map_t[cstart]) { ;
                    } else {
                        map_cmp[cstart] = map_win[cstart];
                    }
                }
                start++;                            // 继续缩小窗口
            }
            end++;                                  // end++

        } else {
            end++;
        }
    }

    return result;
}

int P0076_MinimumWindowSubstring::test() {
    cout << minWindow("ADOBECODEBANC", "ABCC") << endl;
    return 0;
}
