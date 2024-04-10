#include <iostream>
#include <vector>
using namespace std;

// 2024-04-09

int climbStairs(int n) {
    if(n == 1 || n == 2) return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        // 上i层楼梯的方法 = i - 1层 + i - 2层方法
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}