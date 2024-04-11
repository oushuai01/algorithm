#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2024-04-11
// 解析成 0 1 背包问题


bool canPartition(vector<int>& nums) {
    int target = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        target += nums[i];
    }

    if(target % 2 == 0) target = target / 2;
    else return false;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));

    // 初始化
    for(int i = 0; i < dp[0].size(); i++){
        // 将能放得下的 nums[0] 的值设置为 nums[0]
        if(i >= nums[0])
        dp[0][i] = nums[0];
    }

    for(int i = 1; i < nums.size(); i++){
        for(int j = 1; j <= target; j++){
            // dp[i - 1][j] 表示不放 i    
            // dp[i - 1][j - nums[i]] + nums[i] 表示放 i

            // 放不下 i
            if(j < nums[i]) dp[i][j] = dp[i - 1][j];
            // weight 和 value 都是它本身
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
        }
       
    }

    if(dp[nums.size() - 1][target] == target) return true;
    

    return false;
}