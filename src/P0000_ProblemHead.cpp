//
// Created by yongpu on 2019/9/29.
//

#include "P0000_ProblemHead.h"

int Test_Problem(int number) {
    if (number <= 0) {
        cout << "Number error!" << endl;
        return 0;
    }
    if(number == 1){
        P0001_TwoSum P0001;
        P0001.test();
    }
    if(number == 2){
        P0002_AddTwoNumbers P0002;
        P0002.test();
    }
    if(number == 146){
        P0146_LRUCache P0146;
        P0146.test();
    }

    cout << "Not find the number of problem!" << endl;
    return 0;


}
