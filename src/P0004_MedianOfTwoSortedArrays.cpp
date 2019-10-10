//
// Created by yongpu on 2019/10/10 21:40.
//

#include "P0004_MedianOfTwoSortedArrays.h"

/**
 * 题目：寻找两个有序数组的中位数
 * 描述：给定两个大小为m和n的有序数组nums1和nums2，找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))
 * 思路：使用有序数组合并的思路，记录遍历的个数，当满足 cnt = mid 时，则说明已经遍历一半.
 * 备注：数组合并思路.
 */

double P0004_MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();

    if ((len1 == 1 && len2 == 0) || (len1 == 0 && len2 == 1)) {
        if (len1 == 1)
            return nums1[0];
        else
            return nums2[0];
    }

    bool resultFlag = false;    //是否已经得到结果
    bool flag = false;

    if ((len1 + len2) % 2 == 0) //偶数个
    {
        flag = true;    //偶数
    } else {
        flag = false;   //奇数
    }
    int mid = (len1 + len2) / 2;

    int cnt = 0;
    int i = 0;
    int j = 0;

    vector<double> vecNum;
    int index = 0;

    // nums1 和 nums2 一起遍历
    while (i < len1 && j < len2) {
        if (nums1[i] < nums2[j]) {
            index = i;
            cnt++;
            i++;
            if (cnt == mid || cnt == mid + 1) {
                vecNum.push_back(nums1[index]);
            }

        } else {
            index = j;
            cnt++;
            j++;
            if (cnt == mid || cnt == mid + 1) {
                vecNum.push_back(nums2[index]);
            }
        }
        if (cnt == mid + 1) {
            break;
        }
    }
    double result = 0;
    if (vecNum.size() == 2) {       //vecNum的size等于2，说明可以计算结果，不必继续遍历
        if (flag == true)
            result = (vecNum[0] + vecNum[1]) / 2;
        else
            result = vecNum[1];
        resultFlag = true;          //标记，说明已经计算出结果
    }

    if (resultFlag == false) {      //还未计算出结果，还需遍历nums1
        //nums1未结束
        while (i < len1) {
            index = i;
            cnt++;
            i++;
            if (cnt == mid || cnt == mid + 1) {
                vecNum.push_back(nums1[index]);
            }
            if (cnt == mid + 1) {
                break;
            }
        }
    }

    if (resultFlag == false) {      //还未计算出结果，还需遍历nums2
        //nums2未结束
        while (j < len2) {
            index = j;
            cnt++;
            j++;
            if (cnt == mid || cnt == mid + 1) {
                vecNum.push_back(nums2[index]);
            }
            if (cnt == mid + 1) {
                break;
            }
        }
    }

    if(resultFlag == false){        //还未计算出结果
        if (flag == true)
            result = (vecNum[0] + vecNum[1]) / 2;
        else
            result = vecNum[1];
    }

    return result;
}

int P0004_MedianOfTwoSortedArrays::test() {
    vector<int> nums1 = {2,3};
    vector<int> nums2 = {};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}