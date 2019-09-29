//
// Created by yongpu on 2019/9/29.
//

#include "P0146_LRUCache.h"

/**
 * 题目：LRU缓存机制
 * 描述：运用你所掌握的数据结构，设计和实现一个LRU(最近最少使用)缓存机制。它应该支持以下操作：获取数据get和写入数据put.
 * 思路：使用哈希表和双向链表实现
 *
 * 用一个链表记录当前缓存中所有的键值对，并且每次新来的访问都对链表进行重新调整，把最近访问的键值对放到链表头部。
 * 然后为了快速访问缓存中的值，维护一个map，key是实际数据的key，对应的value指向该key在链表中的位置节点，
 * 这样每次添加键值对时，先判断map中是否有该key，若有则修改链表中对应节点的value；若没有则把该键值对添加到链表头部，
 * 去除链表尾部超过规定长度的节点，并在map中添加key以及对应的链表节点指针。
 *
 * 备注：多复习
 */


/**
 * 根据key从缓存中获取数据
 * @param key
 * @return
 */

int P0146_LRUCache::get(int key) {
//    unordered_map<int,list<pair<int,int>>::iterator>::iterator iter = cache_map.find(key);
    auto iter = cache_map.find(key);                    //首先在cahe_map中查找
    if (iter == cache_map.end())                        //未查找到，则返回-1
        return -1;
    int value = iter->second->second;                   //(*it).first得到key，(*it).second得到value。
    cache_list.erase(iter->second);                     //在 cache_list 中删除 iter
    cache_list.push_front(make_pair(key, value));       //将 iter插入到 cache_list 头部
    iter->second = cache_list.begin();                  //将 iter 头部重新赋值给 cache_map

    return value;
}

/**
 * 向缓存中写入数据
 * @param key
 * @param value
 */
void P0146_LRUCache::put(int key, int value) {
//    unordered_map<int,list<pair<int,int>>::iterator>::iterator iter = cache_map.find(key);
    auto iter = cache_map.find(key);
    //1.已存在
    if (iter != cache_map.end()) {                      //已存在
        cache_list.erase(iter->second);                 //在cache_list中移除节点
        cache_list.push_front(make_pair(key, value));   //将(key,value)移植到最新的在cache_list头部
        cache_map[key] = cache_list.begin();            //将头部的 iter 赋值给 cache_map
    }
    //2.还有空闲节点
    else if (cache_map.size() < capNum)                 //当前 cache_map 容量小于 capNum
    {
        cache_list.push_front(make_pair(key, value));   //如果还存在空闲，则直接将 (key,value) 放到 cache_list 首节点
        cache_map[key] = cache_list.begin();            //将头节点的 iter 赋值给 cache_map
    }
    //3.已满，需要删除
    else                                                //当前cache_map容量大于capNum，需要删除元素
    {
        list<pair<int, int> >::iterator iter = cache_list.end();    //定位到 cache_list.end()
        //auto iter = cache_list.end();
        iter--;                                                     //定位到最后一个节点
        cache_map.erase(iter->first);                               //在 cache_map 删除cache_list的最后一个节点
        cache_list.erase(iter);                                     //在 cache_list 删除最后一个节点
        cache_list.push_front(make_pair(key, value));               //在 cache_list 头部插入新节点
        iter = cache_list.begin();                                  //获取 cache_list 头部节点 iter
        cache_map[key] = iter;                                      //将 iter 赋值给 cache_map
    }
}

/**
 * 构造cache
 * @param capacity
 */
P0146_LRUCache::P0146_LRUCache(int capacity) {
    capNum = capacity;
}


int P0146_LRUCache::test() {

    int cap = 2;
    this->capNum = cap;

    int res = 0;

    put(1, 1);
    put(2, 2);

    res = get(1);
    cout << res << endl;

    put(3, 3);

    res = get(2);
    cout << res << endl;

    put(4, 4);

    res = get(1);
    cout << res << endl;

    res = get(3);
    cout << res << endl;

    res = get(4);
    cout << res << endl;

    return 0;
}
