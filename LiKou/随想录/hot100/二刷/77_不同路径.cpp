#include <iostream>
#include <vector>
using namespace std;

// 2024-04-10

int uniquePaths(int m, int n) {
    int dp[m][n];
    // 横竖两条线都只有一条路径
    for(int i = 0; i < n; ++i){
        dp[0][i] = 1;
    }
    for(int i = 0; i < m; ++i){
        dp[i][0] = 1;
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++)
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }

    return dp[m - 1][n - 1];


}