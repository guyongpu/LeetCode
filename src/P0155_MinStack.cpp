//
// Created by yongpu on 2019/10/10 21:15.
//

#include "P0155_MinStack.h"

/**
 * 题目：最小栈
 * 描述：设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈
 * 思路：法1：使用辅助栈，相等时要一起push和pop；法2：只用一个栈，栈顶第一个为最小数据。第二个为实际的数据.
 * 备注：两种方法均须掌握
 */

void P0155_MinStack::push(int x) {
    sta_num.push(x);

    if(sta_min.size() == 0)
    {
        sta_min.push(x);
    }
    else{
        int topMin = sta_min.top();
        if(x <= topMin)
        {
            sta_min.push(x);
        }
    }
}

void P0155_MinStack::pop() {
    int topNum = sta_num.top();
    int topMin = sta_min.top();

    sta_num.pop();

    if(topNum == topMin){
        sta_min.pop();
    }
}

int P0155_MinStack::top() {
    int topNum = sta_num.top();
    return topNum;
}

int P0155_MinStack::getMin() {
    int topMin = sta_min.top();
    return topMin;
}

int P0155_MinStack::test() {
    push(-2);
    push(0);
    push(-3);
    cout << getMin() << endl;
    pop();
    cout << top() << endl;
    cout << getMin() << endl;
    return 0;
}

/** 方法2：只用一个栈
public MinStack() {
    stack = new Stack<Integer>();
}

public void push(int x) {
    if(stack.isEmpty()){
        stack.push(x);
        stack.push(x);
    }else{
        int tmp = stack.top();
        stack.push(x);
        if(tmp<x){
            stack.push(tmp);
        }else{
            stack.push(x);
        }
    }
}

public void pop() {
    stack.pop();
    stack.pop();
}

public int top() {
    return stack.get(stack.size()-2);
}

public int getMin() {
    return stack.top();
}
}
*/