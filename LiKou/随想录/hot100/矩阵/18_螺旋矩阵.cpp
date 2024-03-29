/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-19 10:31:25
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-23 14:23:09
 * @FilePath: \algorithm\LiKou\随想录\hot100\矩阵\18_矩阵置零.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.19
//https://leetcode.cn/problems/spiral-matrix/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <iostream>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int hight = matrix.size();
    int width = matrix[0].size();
    int left = 0, right = width - 1;
    int up = 0, down = hight - 1;
    while(true){
        for(int i = left; i <= right; i++){
            result.push_back(matrix[up][i]);
        }
        up++;
        if(up > down)break;
        for(int i = up; i <= down; i++){
            result.push_back(matrix[i][right - 1]);
        }
        right--;
        if(left > right)break;
        for(int i = right; i >= left; i--){
            result.push_back(matrix[down - 1][i]);
        }
        down--;
        if(up > down)break;
        for(int i = down; i >= up; i--){
            result.push_back(matrix[i][left]);
        }
        left++;
        if(left > right)break;
    }

    return result;

}
// 1,2,3,4
// 5,6,7,8
// 9,10,11,12
// [1,2,3,4,8,12,11,10,9,5,6,7]
// [1,2,3,4,8,12,11,10,9,5,6,7,6]
// 7 8 9
int main(){
    vector<vector<int>> vec = {{1},{2},{3}};
    vector<int> res = spiralOrder(vec);
    for(auto num : res)
    cout << num;
}