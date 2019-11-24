//
// Created by yongpu on 2019/11/24 14:56.
//

#include "P0125_ValidPalindrome.h"

/**
 * 题目：验证回文串
 * 描述：给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写.
 * 思路：先将字符串转为小写，然后用双指针法依次比较左右指针的字符是否相等.
 * 备注：也可以提取出字符和数字，然后翻转对比是否相等
 */

bool P0125_ValidPalindrome::isPalindrome(string s) {
    int len = s.size();
    int left = 0;
    int right = len - 1;

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    while (left < right) {
        while ((left < len) && !(('0' <= s[left] && s[left] <= '9') || ('a' <= s[left] && s[left] <= 'z'))) {
            left++;
        }

        while ((right >= 0) && !(('0' <= s[right] && s[right] <= '9') || ('a' <= s[right] && s[right] <= 'z'))) {
            right--;
        }
        if (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
    }

    return true;
}

int P0125_ValidPalindrome::test() {
    cout << isPalindrome("....") << endl;
    cout << isPalindrome(".,") << endl;
    cout << isPalindrome("Am21ma") << endl;
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}
