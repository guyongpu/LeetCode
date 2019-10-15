//
// Created by yongpu on 2019/10/14 10:53.
//

#include "P0015_3Sum.h"

/**
 * 题目：三数之和
 * 描述：给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组.
 * 思路：先确定一个数，后面的两个数采用双指针做法。第一个数要不与上一个相同，left也不能相同，这样可以避免查找去重.
 * 备注：注意查找去重会超时.
 */

vector<vector<int>> P0015_3Sum::threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int>> result;
    for (int i = 0; i < len; i++) {
        if(i!= 0 && nums[i] == nums[i-1])   //确保第一个数不相同，避免重复
            continue;
        int left = i + 1;
        int right = len - 1;
        int target = 0 - nums[i];
        while (left < right) {
            if (left != i && right != i) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);

                    result.push_back(temp);

                    // 更新 left,确保left不相等
                    int pos_l = left+1;
                    while(nums[pos_l] ==nums[left] && pos_l < right){
                        pos_l++;
                    }
                    left = pos_l;

                    // 更新 right,确保right不相等
                    int pos_r = right-1;
                    while(nums[pos_r] ==nums[right] && pos_r > left){
                        pos_r--;
                    }
                    right = pos_r;

                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            } else if (left == i) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int P0015_3Sum::test() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;
    result = threeSum(nums);
    cout << result.size() << endl;
    return 0;
}
