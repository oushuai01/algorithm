#include <iostream>
#include <vector>
using namespace std;

// 2024-04-10

int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    // dp[i] 拆分后最大乘积
    // 两种方法得到 dp[i]    i * (i - j)  和 j * dp[i - j]
    for(int i = 3; i <= n; i++){
        for(int j = 1; j < i; j++)
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
    }

    return dp[n];

}