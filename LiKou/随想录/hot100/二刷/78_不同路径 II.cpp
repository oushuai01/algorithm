#include <iostream>
#include <vector>
using namespace std;

// 2024-04-10
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.size() == 0) return 0;
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));


    // 障碍物后面的都不能到达  因为只能 右和下 两个方向
    for(int i = 0; i < row; i++){
        if(obstacleGrid[i][0] == 1) break;
        dp[i][0] = 1;
    }

    for(int i = 0; i < col; i++){
        if(obstacleGrid[0][i] == 1) break;
        dp[0][i] = 1;
    }

    // i j 从 1 开始
   for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[row - 1][col - 1];
}