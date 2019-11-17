//
// Created by yongpu on 2019/11/17 15:45.
//

#include "P0096_UniqueBinarySearchTrees.h"

/**
 * 题目：不同的二叉搜索树
 * 描述：给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种
 * 思路：使用动态规划方法，以1-n为根计算.
 * 备注：注意复习
 */

/**
 * 假设n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数，则
 *      G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)
 * 当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，则
 *      f(i) = G(i-1)*G(n-i)f(i)=G(i−1)∗G(n−i)
 * 综合两个公式可以得到 卡特兰数 公式
 *     G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)G(n) = G(0)∗G(n−1) + G(1)∗(n−2) +...+ G(n−1)∗G(0)
 */
int P0096_UniqueBinarySearchTrees::numTrees(int n) {
    if (n == 0) {
        return 1;
    }
    vector<int> G(n + 1, 0);
    G[0] = 1;
    G[1] = 1;
    for (int i = 2; i < n + 1; i++) {           // 以每个数为根进行计算
        for (int j = 1; j < i + 1; j++) {
            int F_i =  G[j - 1] * G[i - j];   // f(i) = G(i-1)*G(n-i)    即，左子树*右子树
            G[i] = G[i] + F_i;                // dp[i] = dp[i] + f(i)
        }
    }
    return G[n];
}

int P0096_UniqueBinarySearchTrees::test() {
    cout << numTrees(0) << endl;
    cout << numTrees(1) << endl;
    cout << numTrees(2) << endl;
    cout << numTrees(3) << endl;
    return 0;
}
