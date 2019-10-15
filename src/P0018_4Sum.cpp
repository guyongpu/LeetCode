//
// Created by yongpu on 2019/10/14 13:57.
//

#include "P0018_4Sum.h"

/**
 * 题目：四数之和
 * 描述：给定一个包含n个整数的数组nums和一个目标值 target，判断nums中是否存在四个元素 a，b，c和d ，使得a+b+c+d的值与target相等？找出所有满足条件且不重复的四元组.
 * 思路：两重循环+双指针做法，即在三数之和的基础上再加上一次循环，每次循环保证不重复.
 * 备注：注意去重.
 */

vector<vector<int>> P0018_4Sum::fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int> > result;
    for (int i = 0; i < len; i++) {
        //1.保证nums[i]不重复
        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        long long int temp_target1 = target - nums[i];
        for (int j = i + 1; j < len; j++) {
            //2.保证nums[j]不重复
            if (j > i + 1 && nums[j - 1] == nums[j])
                continue;
            long long int temp_target2 = temp_target1 - nums[j];
            int left = j + 1;
            int right = len - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == temp_target2) {       //等于 temp_target
                    vector<int> oneRes = {nums[i], nums[j], nums[left], nums[right]};
                    result.push_back(oneRes);

                    //3.保证nums[left]不重复,更新left
                    int temp_l = left + 1;
                    while (temp_l < right && nums[temp_l] == nums[left]) {
                        temp_l++;
                    }
                    left = temp_l;

                    //4.保证nums[right]不重复,更新right
                    int temp_r = right - 1;
                    while (temp_r > left && nums[temp_r] == nums[right]) {
                        temp_r--;
                    }
                    right = temp_r;

                } else if (sum < temp_target2) {    //小于 temp_target2
                    left++;
                } else {                            //大于 temp_target2
                    right--;
                }
            }
        }
    }

    return result;
}

int P0018_4Sum::test() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = fourSum(nums, 0);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << endl;
    }
    return 0;
}
