#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 2024-04-14

int numSquares(int n) {
    // vector<int> sum(100, 0);

    // for(int i = 0; i < sum.size(); i++){
    //     sum[i] = pow(i + 1, 2);
    // }


    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    // for(int i = 0; i < sum.size(); i++){
    //     for(int j = sum[i]; j <= n; j++){
    //         if(dp[j - sum[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - sum[i]] + 1);
    //     }
    // }
    
    for(int j = 1 ; j <= n; j++){  // 遍历背包
        for(int i = 1; i * i <= j; i++){   // 遍历物品
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }

    return dp[n];
}