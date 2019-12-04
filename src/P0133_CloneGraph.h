//
// Created by yongpu on 2019/12/4 20:09.
//

#ifndef LEETCODE_P0133_CLONEGRAPH_H
#define LEETCODE_P0133_CLONEGRAPH_H

#include <iostream>
#include <vector>

using namespace std;

class P0133_Node {
public:
    int val;
    vector<P0133_Node*> neighbors;

    P0133_Node() {}

    P0133_Node(int _val, vector<P0133_Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class P0133_CloneGraph {
public:
    P0133_Node* cloneGraph(P0133_Node* node);
    int test();
};


#endif //LEETCODE_P0133_CLONEGRAPH_H
