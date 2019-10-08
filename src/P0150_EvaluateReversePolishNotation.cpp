//
// Created by yongpu on 2019/10/8.
//

#include "P0150_EvaluateReversePolishNotation.h"

/**
 * 题目：逆波兰表达式求值
 * 描述：根据逆波兰表示法，求表达式的值。有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式
 * 思路：构造一个stack<int>numbers用于存放计算结果，每次遇到运算符则弹出两个元素计算，并把结果存入到numbers中.
 * 备注：题目不难，记得思路即可.
 */

int P0150_EvaluateReversePolishNotation::evalRPN(vector<string> &tokens) {
    int len = tokens.size();
    stack<int> numbers;     //用于存放计算结果
    for (int i = 0; i < len; i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {

            //遇到运算符，则出栈，得到两个运算数
            int num_behind = numbers.top();         //后面的运算数
            numbers.pop();
            int num_front = numbers.top();          //前面的运算数
            numbers.pop();

            int result = 0;                         //保存计算结果
            if (tokens[i] == "+") {
                result = num_front + num_behind;    //加法
            } else if (tokens[i] == "-") {
                result = num_front - num_behind;    //减法
            } else if (tokens[i] == "*") {
                result = num_front * num_behind;    //乘法
            } else {
                result = num_front / num_behind;    //除法
            }

            numbers.push(result);                   //将结果存入栈中

        } else {
            int num = atoi(tokens[i].c_str());      //遇到数字则直接存入栈中
            numbers.push(num);
        }
    }
    int result = numbers.top();                     //numbers只有一个元素，即为计算结果
    return result;
}

int P0150_EvaluateReversePolishNotation::test() {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int result = evalRPN(tokens);
    cout << result << endl;
    return 0;
}
