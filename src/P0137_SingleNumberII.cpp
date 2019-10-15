//
// Created by yongpu on 2019/10/13 15:08.
//

#include "P0137_SingleNumberII.h"

/**
 * 题目：只出现一次的数字II
 * 描述：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素.
 * 思路：采用二进制做法，计算每一位的累加和，如果是K的倍数，则改为为0；否则为1.
 * 备注：记住通用解法.
 *
 * 出现K次的通用解法：
 * 使用一个32维的数组，用这个32维的数组存储所有数里面第0位1的总数，第1位1的总数。。。第31位1的总数。
 * 假如第0位1的个数是k的倍数，那么要求的这个数在该位一定是0，若不是k的倍数，那么要求的这个数在该位一定是1，第1位的1一直到第31位的1的个数同理。
 * 为什么呢？因为假如说数组中的某些数在该位置是1，那么因为这个数要么出现k次，那么出现1次。
 * 因此，该位置一定可以表示成km或者km+1，m代表该位是1的数的种类。
 * 当表示成km的时候代表该位为1的数都是出现k次的，而当表示为km+1的时候代表该位为1的数还有只出现一次的。
 */

int P0137_SingleNumberII::singleNumber(vector<int> &nums) {
    int len = nums.size();
    int result = 0;
    for (int i = 0; i < 32; i++) {
        int cnt = 0;
        for (int j = 0; j < len; j++) {
            if(((nums[j] >> i) & 1) == 1){
                cnt ++;
            }
        }
        if(cnt % 3 == 0){           //能整除，则第i位为0
            result = result;
        }else{                      //不能整除，则第i位为1
            long long int mask = 1;
            mask = mask << i;
            result = result | mask;
        }
    }

    return result;
}

int P0137_SingleNumberII::test() {
    vector<int> nums = {2, 2,2,-3};
    cout << singleNumber(nums) << endl;
    return 0;
}
