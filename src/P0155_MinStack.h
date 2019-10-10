//
// Created by yongpu on 2019/10/10 21:15.
//

#ifndef LEETCODE_P0155_MINSTACK_H
#define LEETCODE_P0155_MINSTACK_H

#include <iostream>
#include <stack>

using namespace std;

class P0155_MinStack {
public:
    P0155_MinStack() {
    }

    void push(int x);

    void pop();

    int top();

    int getMin();

    int test();

    stack <int> sta_num;
    stack <int> sta_min;

};


#endif //LEETCODE_P0155_MINSTACK_H
