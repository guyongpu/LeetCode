//
// Created by yongpu on 2019/10/28 18:56.
//

#include "P0217_ContainsDuplicate.h"

/**
 * 题目：存在重复元素
 * 描述：给定一个整数数组，判断是否存在重复元素，如果任何值在数组中出现至少两次,函数返回true,如果数组中每个元素都不相同，则返回false.
 * 思路：方法1.检测任意两个元素是否重复O,复杂度(n^2)；方法2.排序再遍历是否相邻相等,复杂度(nlogn)；方法3.采用hashmap方法,复杂度(n)；
 * 备注：掌握三种方法.
 */

// 方法1：检测任意两个数是否相等，nums[i]=nums[j]，则返回true；否则返回false
bool P0217_ContainsDuplicate::containsDuplicate_1(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

// 方法2：排序后比较两个相邻元素是否相等
bool P0217_ContainsDuplicate::containsDuplicate_2(vector<int> &nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < len; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}

// 方法3：hashmap方法，检测是否重复
bool P0217_ContainsDuplicate::containsDuplicate_3(vector<int> &nums) {
    unordered_map<int, bool> numsMap;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (numsMap[nums[i]] == true) {
            return true;
        } else {
            numsMap[nums[i]] = true;
        }
    }
    return false;
}

int P0217_ContainsDuplicate::test() {
    vector<int> nums1 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1};
    vector<int> nums4 = {1, 1};
    cout << containsDuplicate_1(nums1) << endl;
    cout << containsDuplicate_1(nums2) << endl;
    cout << containsDuplicate_1(nums3) << endl;
    cout << containsDuplicate_1(nums4) << endl;
    return 0;
}
