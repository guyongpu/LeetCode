//
// Created by yongpu on 2019/10/25 11:38.
//

#include "P0207_CourseSchedule.h"

/**
 * 题目：课程表
 * 描述：给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习，即拓扑是否有环.
 * 思路：方法1.拓扑排序思想，每次找入度为0的节点;方法2.BFS，借助队列实现拓扑排序;方法3.DFS，深度搜索，如果重复访问，则说明成环.
 * 备注：掌握三种方法.
 */

// 方法1.拓扑排序思想
bool P0207_CourseSchedule::canFinish_1(int numCourses, vector<vector<int>> &prerequisites) {
    int pairNum = prerequisites.size();
    int remainNum = pairNum;
    int index = 0;

    vector<int> numIn(numCourses, -1);   //计算入度
    for (int i = 0; i < pairNum; i++) {
        int child = prerequisites[i][0];
        int parent = prerequisites[i][1];
        if (numIn[child] == -1) {
            numIn[child] = 0;
        }
        if (numIn[parent] == -1) {
            numIn[parent] = 0;
        }
        numIn[parent]++;
    }

    vector<bool> Flag(pairNum, true);
    while (FindIndex(numIn, index) == true) {
        for (int i = 0; i < pairNum; i++) {
            if (Flag[i] == false) {
                continue;
            }
            int child = prerequisites[i][0];
            int parent = prerequisites[i][1];
            if (child == index) {
                Flag[i] = false;
                numIn[parent]--;
                remainNum--;
            }
        }
    }

    if (remainNum == 0) {
        return true;
    } else {
        return false;
    }
}

bool P0207_CourseSchedule::FindIndex(vector<int> &numIn, int &index) {
    int len = numIn.size();
    for (int i = 0; i < len; i++) {
        if (numIn[i] == 0) {    //入度为0
            index = i;
            numIn[index] = -1;
            return true;
        }
    }
    return false;
}

/******************************************************/

// 方法2.BFS广度优先
bool P0207_CourseSchedule::canFinish_2(int numCourses, vector<vector<int>> &prerequisites) {
    int pairNum = prerequisites.size();
    vector<int> numIn(numCourses, 0);   //计算入度
    for (int i = 0; i < pairNum; i++) {
        int parent = prerequisites[i][1];
        numIn[parent]++;
    }

    queue<int> InQueue;
    for (int i = 0; i < numCourses; i++) {
        if (numIn[i] == 0) {
            InQueue.push(i);
        }
    }

    int remainNum = numCourses;       // 课程数
    while (InQueue.empty() == false) {  //队列不为空
        int index = InQueue.front();
        InQueue.pop();
        remainNum--;
        for (int i = 0; i < pairNum; i++) {
            if (prerequisites[i][0] == index) {
                int parent = prerequisites[i][1];
                numIn[parent]--;
                if (numIn[parent] == 0) {
                    InQueue.push(parent);
                }

            }
        }
    }

    if (remainNum == 0) {
        return true;
    } else {
        return false;
    }
}

/******************************************************/
// 方法3.DFS深度优先遍历
bool P0207_CourseSchedule::canFinish_3(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graphCourse(numCourses);
    for (int i = 0; i < numCourses; i++) {
        graphCourse[i].resize(numCourses, 0);
    }

    int pairNum = prerequisites.size();
    vector<int> Flag(numCourses, 0);    //
    for (int i = 0; i < pairNum; i++) {
        int x = prerequisites[i][0];
        int y = prerequisites[i][1];
        graphCourse[x][y] = 1;
    }

    for (int i = 0; i < numCourses; i++) {
        if (!dfs(graphCourse, Flag, i)) {
            return false;
        }
    }
    return true;
}


bool P0207_CourseSchedule::dfs(vector<vector<int>> &graphCourse, vector<int> &Flag, int i) {
    if (Flag[i] == 1)        // 访问过
        return false;
    if (Flag[i] == -1)       // 被删除节点
        return true;
    Flag[i] = 1;
    for (int j = 0; j < graphCourse.size(); j++) {
        if (graphCourse[i][j]) {
            if (dfs(graphCourse, Flag, j) == false) {
                return false;
            }
        }
    }
    Flag[i] = -1;
    return true;
}

/******************************************************/

int P0207_CourseSchedule::test() {
    vector<vector<int>> prerequisites = {
            {1, 0},
            {2, 1}
    };
    cout << canFinish_3(3, prerequisites) << endl;
    return 0;
}

