#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
// 2024-04-14

int combinationSum4(vector<int>& nums, int target) {
  vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for(int j = 0; j <= target; j++){
        for(int i = 0; i < nums.size(); i++){
            if(j >= nums[i]) dp[j] += dp[j - nums[i]];
        }
    }

    return dp[target];

}
/*
在求装满背包有几种方案的时候，认清遍历顺序是非常关键的。

如果求组合数就是外层for循环遍历物品，内层for遍历背包。

如果求排列数就是外层for遍历背包，内层for循环遍历物品。

*/