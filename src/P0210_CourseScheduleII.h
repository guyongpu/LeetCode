//
// Created by yongpu on 2019/11/1 10:53.
//

#ifndef LEETCODE_P0210_COURSESCHEDULEII_H
#define LEETCODE_P0210_COURSESCHEDULEII_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class P0210_CourseScheduleII {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites);

    int findIndex(vector<int> numsIndegress);

    int test();
};


#endif //LEETCODE_P0210_COURSESCHEDULEII_H
