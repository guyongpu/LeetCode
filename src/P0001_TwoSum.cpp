//
// Created by yongpu on 2019/9/29.
//

#include "P0001_TwoSum.h"

/**
 * 题目：两数之和
 * 描述：给定一个整数数组nums和target，求该数组中两个和为target的整数，返回下标.
 * 思路：排序，然后使用双指针做法，最后计算下标.
 * 备注：1.排序 2.首尾双指针做法 3.遍历查找下标
 *
 * 示例：
 * 输入：nums = [2, 7, 11, 15], target = 9
 * 返回：[0, 1]
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 *
 * @param nums      数组
 * @param target    目标和
 * @return          和为target的两个数的下标
 */

vector<int> P0001_TwoSum::twoSum(vector<int> &nums, int target) {
    //对nums进行排序
    vector<int> nums_copy =nums;
    sort(nums_copy.begin(), nums_copy.end());
    //用双指针做法
    int index_front = 0;
    int index_last = nums_copy.size() - 1;
    vector<int> result;
    while (index_front < index_last) {
        if (nums_copy[index_front] + nums_copy[index_last] < target) {
            index_front++;
        } else if (nums_copy[index_front] + nums_copy[index_last] > target) {
            index_last--;
        } else {
            int a= nums_copy[index_front];
            int index_a = find(nums.begin(),nums.end(),a) - nums.begin();

            //b不能直接用find函数，否则会出错
            int b =nums_copy[index_last];
            int index_b =0;
            for(int i = 0;i<nums.size();i++){
                if(nums[i] == b && i != index_a)
                {
                    index_b = i;
                    break;
                }
            }
            //下标小数在前，大数在后
            int index_min = min(index_a,index_b);
            int index_max = max(index_a,index_b);
            result.push_back(index_min);
            result.push_back(index_max);
            break;
        }
    }
    return result;
}

int P0001_TwoSum::test() {
//    vector<int> nums = {1, 9, 4, 5, 7, 2, 3, 5, 0, 10, 6, 8};
    vector<int> nums = {-1,-2,-3,-4,-5};
    int target = -8;
    vector<int> result = twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
