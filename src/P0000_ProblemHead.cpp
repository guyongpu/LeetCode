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
    } else if (number == 5) {
        P0005_LongestPalindromicSubstring Solution;
        Solution.test();
    } else if (number == 6) {
        P0006_ZigZagConversion Solution;
        Solution.test();
    } else if (number == 7) {
        P0007_ReverseInteger Solution;
        Solution.test();
    } else if (number == 8) {
        P0008_StringToInteger_atoi Solution;
        Solution.test();
    } else if (number == 9) {
        P0009_PalindromeNumber Solution;
        Solution.test();
    }else if (number == 10) {
        P0010_RegularExpressionMatching Solution;
        Solution.test();
    } else if (number == 11) {
        P0011_ContainerWithMostWater Solution;
        Solution.test();
    }else if (number == 12) {
        P0012_IntegerToRoman Solution;
        Solution.test();
    }else if (number == 13) {
        P0013_RomanToInteger Solution;
        Solution.test();
    }  else if (number == 14) {
        P0014_LongestCommonPrefix Solution;
        Solution.test();
    } else if (number == 15) {
        P0015_3Sum Solution;
        Solution.test();
    } else if (number == 16) {
        P0016_3SumClosest Solution;
        Solution.test();
    } else if (number == 17) {
        P0017_LetterCombinationsOfAPhoneNumber Solution;
        Solution.test();
    } else if (number == 18) {
        P0018_4Sum Solution;
        Solution.test();
    }else if (number == 19) {
        P0019_RemoveNthNodeFromEndOfList Solution;
        Solution.test();
    }else if (number == 20) {
        P0020_ValidParentheses Solution;
        Solution.test();
    }else if (number == 21) {
        P0021_MergeTwoSortedLists Solution;
        Solution.test();
    }else if (number == 24) {
        P0024_SwapNodesInPairs Solution;
        Solution.test();
    }else if (number == 25) {
        P0025_ReverseNodesInkGroup Solution;
        Solution.test();
    } else if (number == 26) {
        P0026_RemoveDuplicatesFromSortedArray Solution;
        Solution.test();
    } else if (number == 27) {
        P0027_RemoveElement Solution;
        Solution.test();
    }else if (number == 28) {
        P0028_ImplementstrStr Solution;
        Solution.test();
    }else if (number == 81) {
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
    } else if (number == 166) {
        P0166_FractionToRecurringDecimal Solution;
        Solution.test();
    } else if (number == 167) {
        P0167_TwoSumII_InputArrayIsSorted Solution;
        Solution.test();
    } else if (number == 168) {
        P0168_ExcelSheetColumnTitle Solution;
        Solution.test();
    } else if (number == 169) {
        P0169_MajorityElement Solution;
        Solution.test();
    } else if (number == 171) {
        P0171_ExcelSheetColumnNumber Solution;
        Solution.test();
    } else if (number == 172) {
        P0172_FactorialTrailingZeroes Solution;
        Solution.test();
    }else if (number == 173) {
        P0173_BinarySearchTreeIterator Solution;
        Solution.test();
    }else if (number == 174) {
        P0174_DungeonGame Solution;
        Solution.test();
    } else if (number == 260) {
        P0260_SingleNumberIII Solution;
        Solution.test();
    } else {
        cout << "Not find the number of problem!" << endl;
    }
    return 0;
}
