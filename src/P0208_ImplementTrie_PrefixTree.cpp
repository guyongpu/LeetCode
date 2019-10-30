//
// Created by yongpu on 2019/10/27 13:45.
//

#include "P0208_ImplementTrie_PrefixTree.h"

/**
 * 题目：实现 Trie(前缀树)
 * 描述：实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作.
 * 思路：定义*tries[MAXN]和is_str变量，不断遍历，遇到不存在的节点是创建新节点，单词结束的节点is_str=true.
 * 备注：重要题目，一定要会手写.
 */

P0208_ImplementTrie_PrefixTree::P0208_ImplementTrie_PrefixTree() {
    is_str = false;
    memset(tries, 0, sizeof(tries));
}

void P0208_ImplementTrie_PrefixTree::insert(string word) {
    P0208_ImplementTrie_PrefixTree *cur = this;
    for (int i = 0; i < word.length(); i++) {
        if (cur->tries[word[i] - 'a'] == nullptr) {
            P0208_ImplementTrie_PrefixTree *new_node = new P0208_ImplementTrie_PrefixTree();
            cur->tries[word[i] - 'a'] = new_node;
        }
        cur = cur->tries[word[i] - 'a'];
    }
    cur->is_str = true;
}

bool P0208_ImplementTrie_PrefixTree::search(string word) {
    P0208_ImplementTrie_PrefixTree *cur = this;
    for(int i = 0 ;i < word.length();i++){
        if(cur != nullptr){
            cur = cur->tries[word[i]-'a'];      // 更新cur指针的指向，使其指向下一个结点
        }
    }

    if (cur != NULL && cur->is_str == true) {
        return true; // cur指针不为空且cur指针指向的结点为一个完整的字符串，则成功找到字符串
    } else {
        return false;
    }
}

bool P0208_ImplementTrie_PrefixTree::startsWith(string prefix) {
    P0208_ImplementTrie_PrefixTree *cur = this;
    for (int i = 0; i < prefix.length(); i++) {
        if (cur != nullptr) {
            cur = cur->tries[prefix[i] - 'a'];
        }
    }
    if (cur == nullptr) {
        return false;
    } else {
        return true;
    }
}

int P0208_ImplementTrie_PrefixTree::test() {
    insert("apple");
    cout << search("apple") << endl;    //true
    cout << search("app") << endl;
    cout << startsWith("app") << endl;
    insert("app");
    cout << search("app") << endl;      //true
    return 0;
}
