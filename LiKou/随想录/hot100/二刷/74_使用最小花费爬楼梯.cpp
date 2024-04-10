#include <iostream>
#include <vector>
using namespace std;

// 2024-04-09

int minCostClimbingStairs(vector<int>& cost) {
    // dp 表示到达 i 层所要的花费
    vector<int> dp(cost.size() + 1, 0);
    for(int i = 2 ; i < dp.size(); i++){
        // dp[i - 1] 跳到 dp[i] 需要花费 dp[i - 1] + cost[i - 1]。
        // dp[i - 2] 跳到 dp[i] 需要花费 dp[i - 2] + cost[i - 2]。

        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[dp.size() - 1];
}