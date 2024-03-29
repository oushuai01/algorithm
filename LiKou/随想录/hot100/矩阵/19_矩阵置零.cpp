/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-23 14:27:55
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-23 14:59:31
 * @FilePath: \algorithm\LiKou\随想录\hot100\矩阵\19_矩阵置零.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE/
 */

//10.23
#include <vector>
#include <iostream>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
   int down = matrix.size() - 1;
   int right = matrix[0].size() - 1;
   vector<int> han(down + 1, 0);
   vector<int> lie(right + 1, 0);
   for(int i = 0; i <= down; i++){
        for(int j = 0; j <= right; j++){
            if(matrix[i][j] == 0){
                han[i] = 1;
                lie[j] = 1;
            }
        }
   }

   //行置0
   for(int i = 0; i <= down; i++){
        if(han[i] == 1){
            matrix[i].assign(matrix[i].size(), 0);
        }
   }

   //列置0
   for(int i = 0; i <= right; i++){
        if(lie[i] == 1){
            for(int j = 0; j <= down; j++){
                matrix[j][i] = 0;
            }
        }
   }
}