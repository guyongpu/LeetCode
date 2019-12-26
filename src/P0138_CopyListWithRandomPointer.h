//
// Created by yongpu on 2019/12/26 14:45.
//

#ifndef LEETCODE_P0138_COPYLISTWITHRANDOMPOINTER_H
#define LEETCODE_P0138_COPYLISTWITHRANDOMPOINTER_H

#include <iostream>
#include <map>

using namespace std;

// Definition for a Node.
class P138_Node {
public:
    int val;
    P138_Node *next;
    P138_Node *random;

    P138_Node() {}

    P138_Node(int _val, P138_Node *_next, P138_Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class P0138_CopyListWithRandomPointer {
public:
    P138_Node *copyRandomList(P138_Node *head);

    int test();
};


#endif //LEETCODE_P0138_COPYLISTWITHRANDOMPOINTER_H
