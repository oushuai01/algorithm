#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
// 2024-04-13

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < coins.size(); i++){
        for(int j = coins[i]; j <= amount; j++){
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

// 对应装满背包有多少种方法 递推公式都是 dp[j] += dp[j - coins[i]];
// 可以重复就从前往后遍历   不能重复就从后往前遍历