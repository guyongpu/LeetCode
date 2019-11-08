//
// Created by yongpu on 2019/11/8 8:40.
//

#include "P0068_TextJustification.h"

/**
 * 题目：文本左右对齐
 * 描述：给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本.
 * 思路：题目不难，按照整个的思路处理即可，唯一需要注意的是i<=len,目的是最后一个单词进行处理，同时处理完后要i=i-1.
 * 备注：编码仔细些.
 */

vector<string> P0068_TextJustification::fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;
    int len = words.size();
    vector<int> index;                                  // 记录下标
    int len_sum = 0;                                    // 保存当前循环的字符总长度
    for (int i = 0; i <= len; i++) {                    // =len 是为了遍历到最后一个单词时能进入下面else子句中处理
        if ((i != len) && (len_sum + words[i].length() <= maxWidth)) {
            index.push_back(i);
            len_sum = words[i].length() + len_sum + 1;  // +1 为空格
        } else {  //将index中下标保存
            string str;
            int word_nums = index.size();               // 单词数
            if (word_nums == 1) {                       // index中只有一个空格，直接在后面补空格
                str = words[index[0]];
                str = str + string(maxWidth - words[index[0]].size(), ' ');
                result.push_back(str);
            } else if (i < len) {
                int word_lens = len_sum - word_nums;            //index中单词总长度
                int space_nums = maxWidth - word_lens;          //可使用的空格数量
                int base_nums = space_nums / (word_nums - 1);   //每个间隔的空格数量
                int remain_num = space_nums % (word_nums - 1);  //左侧多出的空格数量

                int index_nums = index.size();
                for (int k = 0; k < index_nums; k++) {
                    str = str + words[index[k]];
                    if (k < index_nums - 1) {                   // 不是当前行的最后一个单词，则插入空格
                        string space_str(base_nums, ' ');
                        if (k < remain_num) {                   // 左侧前remain_num个要多加一个空格
                            space_str.push_back(' ');
                        }
                        str = str + space_str;
                    }
                }
                result.push_back(str);
            } else {  // i = len                                // 最后一行
                int index_nums = index.size();
                for (int k = 0; k < index_nums; k++) {
                    str = str + words[index[k]];
                    if (k < index_nums - 1) {                   // 单词间只插入一个空格
                        str.push_back(' ');
                    }
                }
                str = str + string(maxWidth - len_sum + 1, ' ');    // 在后面补足空格
                result.push_back(str);
            }

            len_sum = 0;        // len_sum清零
            index.clear();      // 清空index
            if (i < len) {      // i要回退1
                i = i - 1;
            }
        }
    }
    return result;
}

int P0068_TextJustification::test() {
    vector<string> words1 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> words2 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a",
                              "computer.", "Art", "is", "everything", "else", "we", "do"};
    vector<string> result = fullJustify(words3, 20);
    for (int i = 0; i < result.size(); i++) {
        cout << "|" << result[i] << "|" << endl;
    }
    return 0;
}
