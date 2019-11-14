//
// Created by yongpu on 2019/11/13 21:13.
//

#include "P0090_SubsetsII.h"


int P0090_SubsetsII::test() {
    vector<int> aaa = {1, 2, 3, 4};
    auto iter = aaa.begin();
    cout << *iter << endl;
    aaa.insert(aaa.begin(), 9);
    cout << *iter << endl;

    return 0;
}
