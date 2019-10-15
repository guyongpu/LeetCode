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
    }else if (number == 5) {
        P0005_LongestPalindromicSubstring Solution;
        Solution.test();
    }else if (number == 15) {
        P0015_3Sum Solution;
        Solution.test();
    }else if (number == 16) {
        P0016_3SumClosest Solution;
        Solution.test();
    }else if (number == 17) {
        P0017_LetterCombinationsOfAPhoneNumber Solution;
        Solution.test();
    }else if (number == 18) {
        P0018_4Sum Solution;
        Solution.test();
    } else if (number == 81) {
        P0081_SearchInRotatedSortedArrayII Solution;
        Solution.test();
    } else if (number == 136) {
        P0136_SingleNumber Solution;
        Solution.test();
    } else if (number == 137) {
        P0137_SingleNumberII Solution;
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
    } else if (number == 164) {
        P0164_MaximumGap Solution;
        Solution.test();
    } else if (number == 165) {
        P0165_CompareVersionNumbers Solution;
        Solution.test();
    }else if (number == 166) {
        P0166_FractionToRecurringDecimal Solution;
        Solution.test();
    }else if (number == 167) {
        P0167_TwoSumII_InputArrayIsSorted Solution;
        Solution.test();
    }else if (number == 168) {
        P0168_ExcelSheetColumnTitle Solution;
        Solution.test();
    }else if (number == 169) {
        P0169_MajorityElement Solution;
        Solution.test();
    }else if (number == 171) {
        P0171_ExcelSheetColumnNumber Solution;
        Solution.test();
    }else if (number == 172) {
        P0172_FactorialTrailingZeroes Solution;
        Solution.test();
    } else if (number == 260) {
        P0260_SingleNumberIII Solution;
        Solution.test();
    } else {
        cout << "Not find the number of problem!" << endl;
    }
    return 0;
}
