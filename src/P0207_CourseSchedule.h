//
// Created by yongpu on 2019/10/25 11:38.
//

#ifndef LEETCODE_P0207_COURSESCHEDULE_H
#define LEETCODE_P0207_COURSESCHEDULE_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class P0207_CourseSchedule {
public:
    bool canFinish_1(int numCourses, vector<vector<int>> &prerequisites);
    bool FindIndex(vector<int> &numIn, int &index);

    bool canFinish_2(int numCourses, vector<vector<int>> &prerequisites);
    bool canFinish_3(int numCourses, vector<vector<int>> &prerequisites);
    bool dfs(vector<vector<int>> &graphCourse,vector<int> &Flag, int i);

    int test();
};


#endif //LEETCODE_P0207_COURSESCHEDULE_H
