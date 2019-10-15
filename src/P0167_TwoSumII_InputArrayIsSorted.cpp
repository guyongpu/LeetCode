//
// Created by yongpu on 2019/10/14 10:17.
//

#include "P0167_TwoSumII_InputArrayIsSorted.h"

/**
 * 题目：两数之和II-输入有序数组
 * 描述：给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数，返回下标.
 * 思路：使用双指针方法，left从最左，right从最右，逐渐向中间逼近.
 * 备注：注意题目要求下标+1.
 */

vector<int> P0167_TwoSumII_InputArrayIsSorted::twoSum(vector<int> &numbers, int target) {
    int len = numbers.size();
    int left = 0;
    int right = len - 1;

    vector<int> result;
    while (left <= right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            result.push_back(left + 1);
            result.push_back(right + 1);
            break;
        } else if (sum < target) {
            left = left + 1;
        } else if (sum > target) {
            right = right - 1;
        }
    }
    return result;
}

int P0167_TwoSumII_InputArrayIsSorted::test() {
    vector<int> numbers = {2, 7, 11, 15};
    vector<int> result = twoSum(numbers, 198);
    if (result.size() != 0) {
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "Not find!" << endl;
    }
    return 0;
}
