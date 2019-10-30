//
// Created by yongpu on 2019/10/27 13:45.
//

#ifndef LEETCODE_P0208_IMPLEMENTTRIE_PREFIXTREE_H
#define LEETCODE_P0208_IMPLEMENTTRIE_PREFIXTREE_H

#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAXN 26

class P0208_ImplementTrie_PrefixTree {
public:
    bool is_str = false;
    P0208_ImplementTrie_PrefixTree *tries[MAXN];

    /** Initialize your data structure here. */
    P0208_ImplementTrie_PrefixTree();

    /** Inserts a word into the trie. */
    void insert(string word);

    /** Returns if the word is in the trie. */
    bool search(string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);

    int test();
};


#endif //LEETCODE_P0208_IMPLEMENTTRIE_PREFIXTREE_H
