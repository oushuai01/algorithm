#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 2024-04-11
// 解析成 0 1 背包问题
int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    int target = 0;

    for(int i = 0; i < stones.size(); i++){
        sum += stones[i];
    }

    // 将石头分成相当的两堆
    target = sum / 2;

    vector<vector<int>> dp(stones.size(), vector<int>(target +  1, 0));

    // 初始化
    for(int i = stones[0]; i <= target; i++)
        dp[0][i] = stones[0];

    // target 里面最多能放多少石头
    for(int i = 1; i < stones.size(); i++){
        for(int j = 1; j <= target; j++){
            if(j < stones[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
        }
    }

    // 返回两堆石头的差值
    return sum - dp[stones.size() - 1][target] - dp[stones.size() - 1][target];
}

