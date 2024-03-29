/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-23 16:29:19
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-23 17:05:47
 * @FilePath: \algorithm\LiKou\随想录\hot100\矩阵\21_搜索二维矩阵 II.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.23
#include <vector>
#include <iostream>
using namespace std;

//贪心思想
//题解:https://leetcode.cn/problems/search-a-2d-matrix-ii/solutions/2361487/240-sou-suo-er-wei-ju-zhen-iitan-xin-qin-7mtf/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int down = matrix.size() - 1;;
    int left = 0;

    while(down >= 0 && left < matrix[0].size()){
        if(matrix[down][left] > target) down--;
        else if(matrix[down][left] < target) left++;
        else return true;
    }

    return false;
    
}





//勉强通过
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int right = matrix[0].size() - 1;
    int down = matrix.size() - 1;

    int left = 0;
    int up = 0;

    //遍历第一行 确定right
    for(int i = 0; i <= right; i++){
        if(matrix[0][i] > target){
            right = i - 1;
            break;
        }
    }

    //遍历第一列 确定down
    for(int i = 0; i <= down; i++){
        if(matrix[i][0] > target){
            down = i - 1;
            break;
        }
    }

    //遍历最后一行 确定left
    for(int i = right; i >= 0; i--){
        if(matrix[down][i] < target){
            left = i;
            break;
        }
    }
    //遍历最后一列 确定up
    for(int i = down; i >= 0; i--){
        if(matrix[i][right] < target){
            up = i;
            break;
        }
    }

    //从最后一行开始遍历
    for(int i = down; i > up; i--){
        for(int j = right; j > left; j--){
            if(matrix[i][j] == target) return true;
        }
    }

    return false;
}