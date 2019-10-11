//
// Created by yongpu on 2019/9/29.
//

#include "P0000_ProblemHead.h"

int Test_Problem(int number) {
    if (number <= 0) {
        cout << "Number error!" << endl;
        return 0;
    }
    if (number == 1) {
        P0001_TwoSum Solution;
        Solution.test();
    } else if (number == 2) {
        P0002_AddTwoNumbers Solution;
        Solution.test();
    } else if (number == 3) {
        P0003_LongestSubstringWithoutRepeatingCharacters Solution;
        Solution.test();
    } else if (number == 4) {
        P0004_MedianOfTwoSortedArrays Solution;
        Solution.test();
    } else if (number == 146) {
        P0146_LRUCache Solution;
        Solution.test();
    } else if (number == 147) {
        P0147_InsertionSortList Solution;
        Solution.test();
    } else if (number == 148) {
        P0148_SortList Solution;
        Solution.test();
    } else if (number == 149) {
        P0149_MaxPointsOnLine Solution;
        Solution.test();
    } else if (number == 150) {
        P0150_EvaluateReversePolishNotation Solution;
        Solution.test();
    } else if (number == 151) {
        P0151_ReverseWordsInAString Solution;
        Solution.test();
    } else if (number == 152) {
        P0152_MaximumProductSubarray Solution;
        Solution.test();
    } else if (number == 153) {
        P0153_FindMinimumInRotatedSortedArray Solution;
        Solution.test();
    } else if (number == 154) {
        P0154_FindMinimumInRotatedSortedArrayII Solution;
        Solution.test();
    } else if (number == 155) {
        P0155_MinStack Solution;
        Solution.test();
    } else if (number == 160) {
        P0160_IntersectionOfTwoLinkedLists Solution;
        Solution.test();
    } else if (number == 162) {
        P0162_FindPeakElement Solution;
        Solution.test();
    } else {
        cout << "Not find the number of problem!" << endl;
    }
    return 0;
}
