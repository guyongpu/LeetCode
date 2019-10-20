//
// Created by yongpu on 2019/10/17 10:37.
//

#include "P0026_RemoveDuplicatesFromSortedArray.h"

/**
 * 题目：删除排序数组中的重复项
 * 描述：给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 思路：用双指针方法，法1：删除重复元素；法2：覆盖重复元素的值.
 * 备注：法2的思路要掌握，时间复杂度更低.
 *
 */


//法1：在nums上进行删除操作，较为耗时.
int P0026_RemoveDuplicatesFromSortedArray::removeDuplicates_1(vector<int> &nums) {
    int len = nums.size();
    if (len <= 1)
        return len;

    int index = 0;
    int detect = 1;
    for (int i = index; i < len - 1;) {
        if (nums[i] == nums[detect]) {
            while (nums[i] == nums[detect] && detect < len) {
                nums.erase(nums.begin() + detect);
                len--;
            }
            i++;
            detect++;
        } else {
            detect++;
            i++;
        }
    }
    return len;
}

//法2：将nums[j+1]复制到nums[i]上，避免删除耗时
int P0026_RemoveDuplicatesFromSortedArray::removeDuplicates_2(vector<int> &nums) {
    int len = nums.size();
    if (len <= 1)
        return len;
    int index = 0;
    for (int detect = 1; detect < len;) {
        if (nums[index] == nums[detect]) {
            while (nums[index] == nums[detect] && detect < len) {
                detect++;
            }
            if(detect < len){
                nums[index+1] = nums[detect];
                index++;
                detect++;
            }
        } else {
            nums[index+1] = nums[detect];
            index++;
            detect++;
        }
    }
    return index+1;
}

int P0026_RemoveDuplicatesFromSortedArray::test() {
    vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums2 = {0, 1, 3};
    vector<int> nums3 = {0, 0, 0, 0, 0, 0};
    vector<int> nums4 = {1, 1};
    cout << removeDuplicates_2(nums1) << endl;
    cout << removeDuplicates_2(nums2) << endl;
    cout << removeDuplicates_2(nums3) << endl;
    cout << removeDuplicates_2(nums4) << endl;
    return 0;
}
