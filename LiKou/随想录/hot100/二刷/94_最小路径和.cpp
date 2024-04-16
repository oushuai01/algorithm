#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;

// 2024-04-16

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

    dp[0][0] = grid[0][0];
    for(int j = 1; j < grid[0].size(); j++){
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for(int i = 1; i < grid.size(); i++){
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for(int i = 1; i < grid.size(); i++){
        for(int j = 1; j < grid[i].size(); j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[grid.size() - 1][grid[0].size() - 1];
}

// 原地dp
int minPathSum_(vector<vector<int>>& grid) {
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(i == 0 && j == 0) continue;
            else if(i == 0) grid[i][j] = grid[i][j - 1] + grid[i][j];
            else if(j == 0) grid[i][j] = grid[i - 1][j] + grid[i][j];
            else grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
    }
    return grid[grid.size() - 1][grid[0].size() - 1];
}
