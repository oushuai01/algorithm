#include <iostream>
#include <vector>
using namespace std;

// 2024-04-02

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int up = 0, down = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    int mid;
    // 判断存在哪一层  up 的值就是存在的层数
    while(up <= down){
        mid = (up + down) / 2;
        if(target > matrix[mid][right]) 
        up = mid + 1;
        else if(target < matrix[mid][right])
        down = mid - 1;
        else
        return true;
    }
    // 如果up值比数组长度大  说明大于最大值
    if(up > (matrix.size() - 1)) return false;

    // 确定这一层是否有这个值
    while(left <= right){
        mid = (left + right) / 2;
        if(target > matrix[up][mid])
        left = mid + 1;
        else if(target < matrix[up][mid])
        right = mid - 1;
        else
        return true;
    }

    return false;
}