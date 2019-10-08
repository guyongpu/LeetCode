"# LeetCode" 
# 仓库说明
## 1.时间轴
|<center>时间</center>|<center>记录内容</center>|<center>备注</center>|
|:---|:---|:---|
|2019年9月29日10:12:19|开始着手刷题|起步|

## 2.内容描述
&emsp;&emsp;本仓库链接：https://github.com/guyongpu/LeetCode.git  
&emsp;&emsp;本仓库为LeetCode刷题记录，网址为：https://leetcode-cn.com/problemset/all/ ，[点击跳转到LeetCode中文题库](https://leetcode-cn.com/problemset/all/)
每个题的代码放在src中，在main.cpp设置number的值，numbers为题目编号，然后运行测试函数即可，例如需要运行题1时，在main.cpp中设置number=1即可:
~~~ c++
#include <iostream>

#include "src/P0000_ProblemHead.h"

using namespace std;

int main() {
    int number = 1;
    Test_Problem(number);
    cout << "Probelem " << number << " test finish!" << endl;
    return 0;
}
~~~

&emsp;&emsp;然后点击运行即可，题1结果如下：
~~~c++
2 4
Probelem 1 test finish!

Process finished with exit code 0
~~~

## 3.文件说明
|<center>文件名</center>|<center>内容描述</center>|
|:---|:---|
|P0000_CommonHead.h|用于声明一些公用的结构体或者函数，如树节点、链表节点等，在需要的时候引用.|
|P0000_ProblemHead.h|用于测试的头文件，则其中引入各个文件的头文件，用于创建各个问题的类.|
|P0000_ProblemHead.cpp|用于测试的源程序，在switch函数中创建并调用各个问题类的test()函数进行运行测试.|
|Pxxxx_*******.h|表示编号为xxxx问题的类的头文件.|
|Pxxxx_*******.cpp|表示编号为xxxx问题的类的头文件相对应的源程序.|

## 4.刷题日志
|<center>题号</center>|<center>题目名</center>|<center>完成日期</center>|<center>描述</center>|<center>备注</center>|
|:---:|:---:|:---:|:---|:---|
|P0001|两数之和|2019.9.29|描述：给定一个整数数组nums和target，求该数组中两个和为target的整数，返回下标.<br>思路：排序，然后使用双指针做法，最后计算下标.<br>复杂度：空间O(n),时间O(3n)|排序+首尾双指针|
|P0002|两数相加|2019.9.29|描述：两个非空的链表用来表示两个非负的整数，将这两个数相加起来，则会返回一个新的链表来表示它们的和.<br>思路：采用链表合并思想，1.当都不为空时，逐个合并；2.其中一个为空，则单独对另一个处理；3.最后处理carry可能存在的进位.<br>复杂度：空间O(max(N,M)),时间O(max(N,M))|链表合并思想+处理最后的carry|
|P0146|LRU缓存机制|2019.9.29|描述：运用你所掌握的数据结构，设计和实现一个LRU(最近最少使用)缓存机制。它应该支持以下操作：获取数据get和写入数据put.<br>思路：使用哈希表和双向链表实现.|多复习|
|P0147|对链表进行插入排序|2019.9.30|描述：按照插入排序的思想，对链表进行插入排序.<br>思路：在进行插入排序的时候，对当前待处理节点要保留 NodeFront、NodeCurrent、NodeNext三个节点，对于比较节点要保留 pNode0 和 pNode。|面试题，要复习|
|P0148|排序链表|2019.10.8|描述：在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序.<br>思路：对链表进行快速排序或归并排序进行实现均可，和普通的数组排序有所不同，要注意区分.|该题比较重要，要注意复习|
|P0149|直线上最多的点|2019.10.8|描述：给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上.<br>思路：对每个点进行计算通过第i个点的点的数量，对于每一个点，将斜率的分子分母约分后存储到map中.|重合的点不用计算，直接+1就行.|