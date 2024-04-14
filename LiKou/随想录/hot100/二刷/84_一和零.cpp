#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
// 2024-04-13
    
    
int findMaxForm(vector<string>& strs, int m, int n) {
    // dp 表示 m 个0   n 个1 所能背的最大个数
    // 都初始化为0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(string str : strs){   // 遍历物品
        int x = 0;
        int y = 0;
        for(char c : str){
            if(c == '0') x++;
            else y++;
        }
        if(x > m || y > n) continue;
        // 从后往前遍历
        for(int i = m; i >= x; i--){
            for(int j = n; j >= y; j--){
                dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);
            }
        }
    }

    return dp[m][n];
}