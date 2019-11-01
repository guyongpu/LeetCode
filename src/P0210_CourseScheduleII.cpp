//
// Created by yongpu on 2019/11/1 10:53.
//

#include "P0210_CourseScheduleII.h"

/**
 * 题目：课程表II
 * 描述：给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序.
 * 思路：每次找入度为0的节点，直到所有全部找完，如果还剩下课程没有处理，则说明不能完成，否则翻转后返回result.
 * 备注：也可以采用BFS或DFS
 */

vector<int> P0210_CourseScheduleII::findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> numsIndegress(numCourses, 0);
    // 计算入度
    int len = prerequisites.size();
    for (int i = 0; i < len; i++) {
        int course = prerequisites[i][1];
        numsIndegress[course]++;
    }

    vector<int> result;
    int remainNum = numCourses;
    vector<bool> preFlag(len, true);
    while (1) {
        int index = findIndex(numsIndegress);
        if (index == -1) {
            break;
        }
        numsIndegress[index] = -1;
        remainNum--;
        result.push_back(index);
        for (int i = 0; i < len; i++) {
            if (prerequisites[i][0] == index && preFlag[i] == true) {
                numsIndegress[prerequisites[i][1]]--;
                preFlag[i] = false;
            }
        }
    }
    if (remainNum == 0) {
        reverse(result.begin(),result.end());
        return result;
    }
    return vector<int>();
}

int P0210_CourseScheduleII::findIndex(vector<int> numsIndegress) {
    int courseNum = numsIndegress.size();
    for (int i = 0; i < courseNum; i++) {
        if (numsIndegress[i] == 0) {
            return i;
        }
    }
    return -1;
}

int P0210_CourseScheduleII::test() {
    vector<vector<int>> prerequisites = {
            {1, 0},
            {2, 0},
            {3, 1},
            {3, 2}
    };
    vector<int> result = findOrder(4, prerequisites);
    int len = result.size();
    for (int i = 0; i < len; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
