//
// Created by yongpu on 2019/10/28 18:58.
//

#include "P0220_ContainsDuplicateIII.h"

/**
 * 题目：存在重复元素III
 * 描述：给定一个整数数组，判断数组中是否有两个不同的索引i和j，使得 nums[i]和nums[j]的差的绝对值最大为t，并且i和j之间的差的绝对值最大为k.
 * 思路：采用暴力法的滑动窗口会超时，因此采用二叉搜索树思想用set解决，num_double-t <= x，寻找第一个大于等于num_double-t的元素计算.
 * 备注：掌握暴力法和二叉树搜索树set方法.
 */

// 方法1：维护一个set，思想与滑动窗口类似
bool P0220_ContainsDuplicateIII::containsNearbyAlmostDuplicate_1(vector<int> &nums, int k, int t) {
    int len = nums.size();
    set<double> winSet;
    for (int i = 0; i < len; i++) {
        if (winSet.size() == k + 1) {
            winSet.erase(nums[i - k - 1]);
        }
        double num_double = nums[i];
        double t_double = t;
        double dif = num_double - t_double;
        // num_double-x <= t  ===>  num_double-t <= x
        set<double>::iterator iter_low = winSet.lower_bound(dif);   //寻找第一个大于等于dif的元素，然后验证
        if (iter_low != winSet.end()) {
            double iter_num = *iter_low;
            if (abs(iter_num - num_double) <= t) {
                return true;
            }
        }

        winSet.insert(num_double);
    }

    return false;
}


// 方法2：维护一个k+1大小的窗口，每次判断窗口的当前元素是否满足条件
bool P0220_ContainsDuplicateIII::containsNearbyAlmostDuplicate_2(vector<int> &nums, int k, int t) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; (j <= i + k) && (j < len); j++) {
            long long a = nums[i];
            long long b = nums[j];
            long long dif = abs(a - b);
            if (dif <= (long long) t) {
                return true;
            }
        }
    }
    return false;
}

int P0220_ContainsDuplicateIII::test() {
    vector<int> nums1 = {1, 2, 3, 1};
    cout << containsNearbyAlmostDuplicate_1(nums1, 3, 0) << endl;
    vector<int> nums2 = {1, 0, 1, 1};
    cout << containsNearbyAlmostDuplicate_1(nums2, 1, 2) << endl;
    vector<int> nums3 = {1, 5, 9, 1, 5, 9};
    cout << containsNearbyAlmostDuplicate_1(nums3, 2, 3) << endl;
    vector<int> nums4 = {-1, 2147483647};
    cout << containsNearbyAlmostDuplicate_1(nums4, 1, 2147483647) << endl;
    vector<int> nums5 = {5, 5};
    cout << containsNearbyAlmostDuplicate_1(nums5, 3, 0) << endl;
    vector<int> nums6 = {-1, -1};
    cout << containsNearbyAlmostDuplicate_1(nums6, 1, 0) << endl;
    vector<int> nums7 = {7, 2, 8};
    cout << containsNearbyAlmostDuplicate_1(nums7, 2, 1) << endl;
    vector<int> nums8 = {1, 1, 1,1,1,1,1};
    cout << containsNearbyAlmostDuplicate_1(nums8, 3, 3) << endl;
    return 0;
}
