//
// Created by yongpu on 2019/11/9 15:17.
//

#include "P0074_SearchA2DMatrix.h"

/**
 * 题目：搜索二维矩阵
 * 描述：编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值.
 * 思路：方法1.使用2次二分查找，1次先确定所在行，另1次在行中查找是否存在数据；方法2.将矩阵映射为一条长链表，然后直接二分查找.
 * 备注：掌握方法1和2
 */

bool P0074_SearchA2DMatrix::searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0) {
        return false;
    }
    int m = matrix[0].size();
    if(m == 0){
        return false;
    }

    // 先找行
    int low = 0;
    int high = n - 1;
    int mid = 0;
    int targ_row = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (matrix[mid][0] == target) {
            return true;
        } else if (matrix[mid][0] < target) {
            if (mid == n - 1) {
                targ_row = n - 1;
                break;
            } else if (matrix[mid + 1][0] <= target) {
                low = mid + 1;
            } else {
                targ_row = mid;
                break;
            }
        } else {    //matrix[mid][0] > target)
            if (mid == 0) {
                return false;
            } else if (matrix[mid - 1][0] >= target) {
                high = mid - 1;
            } else {
                targ_row = mid-1;
                break;
            }
        }
    }
//    cout << "targ_row = " << targ_row << endl;

    // 在第 targ_row 行进行二分查找
    low = 0;
    high = m-1;
    while(low <= high){
        mid = low + (high-low)/2;
        if(matrix[targ_row][mid] == target){
            return true;
        }else if(matrix[targ_row][mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return false;
}

int P0074_SearchA2DMatrix::test() {

    vector<vector<int>> matrix = {
            {}
//            {1,  3,  5,  7},
//            {10, 11, 16, 20},
//            {23, 30, 34, 50},
//            {65, 30, 34, 50},
//            {75, 77, 78, 82},
//            {85, 87, 90, 93},
    };

    cout << searchMatrix(matrix, 78) << endl;

    return 0;
}
