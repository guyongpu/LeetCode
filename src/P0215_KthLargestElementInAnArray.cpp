//
// Created by yongpu on 2019/12/27 19:25.
//

#include "P0215_KthLargestElementInAnArray.h"

/**
 * 题目：数组中的第K个最大元素
 * 描述：在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素.
 * 思路：方法1.遍历K次，每次找最大值；方法2.使用优先队列构造最小堆，维护一个大小为K的堆
 * 备注：掌握方法1和方法2
 */

// 方法1.遍历K次
int P0215_KthLargestElementInAnArray::findKthLargest_1(vector<int> &nums, int k) {
    int len = nums.size();
    vector<bool> visit(len, true);
    int maxNum = 0;
    int index = 0;
    for (int i = 0; i < k; i++) {
        maxNum = INT_MIN;
        index = 0;
        for (int j = 0; j < len; j++) {
            if (visit[j]) {
                if (nums[j] > maxNum) {
                    maxNum = nums[j];
                    index = j;
                }
            }
        }
        visit[index] = false;
    }
    return maxNum;
}

// 方法2.最小堆
int P0215_KthLargestElementInAnArray::findKthLargest_2(vector<int> &nums, int k) {
    int result = 0;
    int len = nums.size();

    if (len == 0 || k > len) {
        return 0;
    }

    // 构造最小堆
    priority_queue<int, vector<int>, greater<int>> store;

    // 堆中维持k个最大数
    for (int i = 0; i < len; i++) {
        store.push(nums[i]);
        if (store.size() > k) {
            store.pop();    // 将堆顶元素去除
        }
    }

    result = store.top();
    return result;

}

int P0215_KthLargestElementInAnArray::test() {
    vector<int> array1 = {3, 2, 1, 5, 6, 4};
    cout << findKthLargest_2(array1, 2) << endl;

    vector<int> array2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest_2(array2, 4) << endl;
    return 0;
}
