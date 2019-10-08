//
// Created by yongpu on 2019/10/8.
//

#include "P0151_ReverseWordsInAString.h"

/**
 * 题目：翻转字符串里的单词
 * 描述：给定一个字符串，逐个翻转字符串中的每个单词。
 * 思路：运用公式 BA = （A^T B^T)^T，先对每个单词翻转，然后再整个字符串翻转。最后去除多余空格，去除首尾空格，及处理特殊字符串.
 * 备注：题目本身不难，但是在处理空格时要仔细.
 */

string P0151_ReverseWordsInAString::reverseWords(string s) {
    int len = s.length();
    int index_s = 0;
    int index_l = 0;

    //翻转单个单词
    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') {
            index_s = i;
            for (int j = i + 1; j < len; j++) {
                if (s[j] == ' ') {
                    index_l = j - 1;
                    reverse(s.begin() + index_s, s.begin() + index_l + 1);
                    i = j;
                    break;
                } else if (j == len - 1) {
                    index_l = j;
                    reverse(s.begin() + index_s, s.begin() + index_l + 1);
                    i = j;
                    break;
                }
            }

        }
    }
    //1.多个空格只保留一个
    int i = 0;
    while (s[i] != '\0' && s[i + 1] != '\0') {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            s.erase(s.begin() + i);
        } else {
            i++;
        }
    }
    //2.去掉后面的空格，去掉s前面的即可，应该翻转后等价于去掉后面的
    int j = 0;
    int index1 = 0;
    while (s[j] != '\0') {
        if (s[j] == ' ') {
            j++;
        } else {
            index1 = j;
            break;
        }
    }
    s.erase(s.begin(), s.begin() + index1);

    reverse(s.begin(), s.end());            //翻转字符串

    //3.去掉后面的空格
    int k = 0;
    int index2 = 0;
    while (s[k] != '\0') {
        if (s[k] == ' ') {
            k++;
        } else {
            index2 = k;
            break;
        }
    }
    s.erase(s.begin(), s.begin() + index2);

    if (s.length() <= 1){           //到达该步时，如输入是"    "，则已经变为" ",只需再判断是否是“ ”即可，如是则返回“”
        if(s==" ")
            return string("");
        else
            return s;
    }
    return s;
}

int P0151_ReverseWordsInAString::test() {
    string s = "the sky is blue";
    string str = reverseWords(s);
    cout << "|" << reverseWords("the sky is blue") << "|" << endl;
    cout << "|" << reverseWords("  hello world!  ") << "|" << endl;
    cout << "|" << reverseWords("a good   example") << "|" << endl;
    cout << "|" << reverseWords("   ") << "|" << endl;
    cout << "|" << reverseWords("     ") << "|" << endl;
    cout << "|" << reverseWords("  a ") << "|" << endl;
    cout << "|" << reverseWords(" ") << "|" << endl;
    return 0;
}
