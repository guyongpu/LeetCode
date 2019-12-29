//
// Created by yongpu on 2019/12/29 12:15.
//

#include "P0292_NimGame.h"

/**
 * 题目：Nim游戏
 * 描述：编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏.
 * 思路：方法1.数学分析，return n%4;方法2.递归法，当对手三种情况都必胜时，n对应的情况才必败；方法3.记忆化递归
 * 备注：掌握方法1、2、3
 */


// 方法1.数学分析法
bool P0292_NimGame::canWinNim_1(int n) {
    return n % 4;
}

// 方法2.递归法
bool P0292_NimGame::canWinNim_2(int n) {
    //time1++;
    if (n <= 3) {
        return true;
    }
    if (n == 4) {
        return false;
    }
    // 下一步对手走，canWinNim_2(n - 1)，canWinNim_2(n - 2)，canWinNim_2(n - 3),当对手三种情况都必胜时，n对应的情况才必败.
    return !(canWinNim_2(n - 1) && canWinNim_2(n - 2) && canWinNim_2(n - 3));
    return !canWinNim_2(n - 1) || !canWinNim_2(n - 2) || !canWinNim_2(n - 3);
}

// 方法3.记忆化递归
bool canWinNim_sub(int n, map<int, bool> &checkMap) {
    //time2++;
    if (checkMap.find(n) != checkMap.end()) {
        return checkMap[n];
    }
    bool flag;
    if (n <= 3) {
        flag = true;
    } else if (n == 4) {
        flag = false;
    } else {
        flag = !(canWinNim_sub(n - 1, checkMap) && canWinNim_sub(n - 2, checkMap) && canWinNim_sub(n - 3, checkMap));
    }
    checkMap[n] = flag;
    return checkMap[n];
}

bool P0292_NimGame::canWinNim_3(int n) {
    map<int, bool> checkMap;
    return canWinNim_sub(n, checkMap);
}

int P0292_NimGame::test() {
    cout << canWinNim_1(20) << endl;
    cout << canWinNim_2(20) << endl;
    cout << canWinNim_3(20) << endl;
//    cout << "time1 = " << time1 << endl;
//    cout << "time2 = " << time2 << endl;
    return 0;
}
