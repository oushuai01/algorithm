#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 2024-04-02

vector<string> path;
vector<vector<string>> result;

bool cheak(int row, int col, vector<string>& path_temp){
    // 检测横排 不需要检查 在放置过程中就一排只有一个

    // 检测竖排
    for(int i = 0; i < row; i++){
        // 剪枝操作 只需要检查此横排对应的竖排有没有被占用就行
        if(path_temp[i][col] == 'Q') return false;
    }

    // 检查左上
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--){
        if(path_temp[i][j] == 'Q') return false;
    }

    // 检查右上
    for(int i = row - 1, j = col + 1; i >= 0 && j < path_temp.size(); i--,j++){
        if(path_temp[i][j] == 'Q') return false;
    }

    return true;
}

void backTrack(int n, int row){
    if(row == n) {
        result.push_back(path);
        return;
    }
    // 判断是否能成
    for(int col = 0; col < n; col++){
        if(cheak(row, col, path)){ // 验证合法就可以放
            path[row][col] = 'Q'; // 放置皇后
            backTrack(n, row + 1);
            path[row][col] = '.'; // 回溯 撤销皇后
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    path = vector<string>(n, string(n, '.'));
    backTrack(n, 0);
    return result;
}