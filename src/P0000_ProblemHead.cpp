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
    else if(number == 2){
        P0002_AddTwoNumbers P0002;
        P0002.test();
    }
    else if(number == 146){
        P0146_LRUCache P0146;
        P0146.test();
    }
    else if(number == 147){
        P0147_InsertionSortList P0147;
        P0147.test();
    }
    else if(number == 148){
        P0148_SortList P0148;
        P0148.test();
    }
    else if(number == 149){
        P0149_MaxPointsOnLine P0149;
        P0149.test();
    }
    else{
        cout << "Not find the number of problem!" << endl;
    }
    return 0;
}
