//
// Created by yongpu on 2019/11/4 16:52.
//

#include "P0060_PermutationSequence.h"

/**
 * 题目：第K个排列
 * 描述：给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列，输出第K个排列.
 * 思路：找规律，ans=ans+nums[(k-1)/arr[n]],进行n次计算即可得到结果.
 * 备注：要复习这个题
 */

/**
 * 假设n=5,k=35,
 * n为5的全排列就是首位为1-5的如下排列的所有
 * 1_,,,2,,,3,,,4,,,5,,,每个各有24个排列，组成12345的全排列
 * 由于k=35<48,也就是说第35个肯定在首位为2的全排列里边,所以第一个取2。
 * 接下来就是考虑剩下1345这四个数的全排列里边取第k=35-24=11个，
 * 1,,3,,4,,5,,每个各有6个排列，组成1345的全排列，
 * 由于k=11<12,也就是说第11个肯定在首位为3的全排列里边，所以第二个数取3
 * 接下来就是考虑剩下145这三个数的全排列里边取第k=11-6=5个，
 * 1,4,5,_每个各有2个排列，组成145的全排列
 * 由于k=5<6,也就是说第5个肯定在首位为5的全排列里边，所以第三个数取5
 * 接下来就是考虑剩下14这两个数的排列里边取第k=5-4=1个
 * 1_4_每个各有1个排列，组成14的排列，
 * 由于k=1,所以第四个数取1
 * 最后加上剩下的最后一个4，结果就是23514
 */
string P0060_PermutationSequence::getPermutation(int n, int k) {
    vector<int> arr(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] * i;
    }

    string nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i + '0');
    }
    string answer;
    int interval, loop_times = n;
    for (int i = 0; i < loop_times; i++) {
        n--;
        interval = (k - 1) / arr[n];
        answer = answer + nums[interval];
        nums.erase(nums.begin() + interval);
        k = k - interval * arr[n];
    }
    return answer;
}

int P0060_PermutationSequence::test() {
    cout << getPermutation(4, 10) << endl;
    cout << getPermutation(4, 1) << endl;
    return 0;
}
