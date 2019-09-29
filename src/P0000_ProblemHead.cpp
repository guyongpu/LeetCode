//
// Created by yongpu on 2019/9/29.
//

#include "P0000_ProblemHead.h"

int Test_Problem(int number) {
    if (number <= 0) {
        cout << "Number error!" << endl;
        return 0;
    }

    switch (number) {
        case 1:
            P0001_TwoSum P0001;
            P0001.test();
            break;
        case 2:
            P0002_AddTwoNumbers P0002;
            P0002.test();
            break;
        default:
            cout << "Not find the number of problem!" << endl;
    }
    return 0;


}
