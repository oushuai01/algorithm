#include <iostream>
#include <vector>
using namespace std;

// 2024-04-09

int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 1) return max(nums[0], nums[1]);
    // dp 表示最大金额
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++){
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[nums.size() - 1];
}