//
// Created by yongpu on 2019/9/29.
//

#ifndef LEETCODE_P0146_LRUCACHE_H
#define LEETCODE_P0146_LRUCACHE_H

#include <iostream>
#include <vector>
#include <list>
#include <map>              //哈希表头文件

using namespace std;

class P0146_LRUCache {
public:
    int test();

    int get(int key);

    void put(int key, int value);

    P0146_LRUCache(int cap = 0);

    int capNum;

    map<int,list<pair<int,int>>::iterator> cache_map;
    list<pair<int,int> > cache_list;
};


#endif //LEETCODE_P0146_LRUCACHE_H
