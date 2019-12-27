//
// Created by yongpu on 2019/12/27 22:08.
//

#include "P0231_PowerOfTwo.h"

bool P0231_PowerOfTwo::isPowerOfTwo(int n) {
    if(n <= 0){
        return false;
    }
    while (1) {
        if (n == 1) {
            return true;
        }

        if ((n & 1) == 0) {
            n = n >> 1;
        } else {
            return false;
        }
    }
    return false;
}

int P0231_PowerOfTwo::test() {
    cout << isPowerOfTwo(16) << endl;
    cout << isPowerOfTwo(218) << endl;
    return 0;
}
