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
        P0001_TwoSum P0001;
        P0001.test();
    } else if (number == 2) {
        P0002_AddTwoNumbers P0002;
        P0002.test();
    } else if (number == 3) {
        P0003_LongestSubstringWithoutRepeatingCharacters P0003;
        P0003.test();
    }else if (number == 4) {
        P0004_MedianOfTwoSortedArrays P0004;
        P0004.test();
    } else if (number == 146) {
        P0146_LRUCache P0146;
        P0146.test();
    } else if (number == 147) {
        P0147_InsertionSortList P0147;
        P0147.test();
    } else if (number == 148) {
        P0148_SortList P0148;
        P0148.test();
    } else if (number == 149) {
        P0149_MaxPointsOnLine P0149;
        P0149.test();
    } else if (number == 150) {
        P0150_EvaluateReversePolishNotation P0150;
        P0150.test();
    } else if (number == 151) {
        P0151_ReverseWordsInAString P0151;
        P0151.test();
    } else if (number == 152) {
        P0152_MaximumProductSubarray P0152;
        P0152.test();
    } else if (number == 153) {
        P0153_FindMinimumInRotatedSortedArray P0153;
        P0153.test();
    } else if (number == 154) {
        P0154_FindMinimumInRotatedSortedArrayII P0154;
        P0154.test();
    }else if(number == 155){
        P0155_MinStack P0155;
        P0155.test();
    }
    else {
        cout << "Not find the number of problem!" << endl;
    }
    return 0;
}
