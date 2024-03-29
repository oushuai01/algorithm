/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-23 15:46:20
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-11 16:16:19
 * @FilePath: \algorithm\LiKou\随想录\hot100\矩阵\20_旋转图像.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.23
#include <vector>
#include <iostream>
using namespace std;
//题解
//https://leetcode.cn/problems/rotate-image/solutions/1228078/48-xuan-zhuan-tu-xiang-fu-zhu-ju-zhen-yu-jobi/
//  A ------> B
//  ^         |
//  |         |
//  |         v
//  D <------ C

// 找好A->B->C->D->A的规律   保存A的值  从后往前覆盖
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n / 2; i++){
        // 如果 n 是奇数 就多一行作为起点 因为 (n + 1)/2 向下取整的
        for(int j = 0; j < (n + 1)/2; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 -j][i];
            matrix[n - 1 -j][i] = matrix[n - 1 -i][n - 1 - j];
            matrix[n - 1 -i][n - 1 - j] = matrix[j][n -1 - i];
            matrix[j][n -1 - i] = temp;
        }
    }
}

