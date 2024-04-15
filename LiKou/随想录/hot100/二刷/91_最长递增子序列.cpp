#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;

// 2024-04-15

int lengthOfLIS(vector<int>& nums) {
    // dp[i] 的值代表 nums 以 nums[i] 结尾的最长子序列长度
    // dp[i] 所有元素置 1，含义是每个元素都至少可以单独成为子序列，此时长度都为 1。
    vector<int> dp(nums.size() + 1, 1);
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            // 当 nums[i]>nums[j]时： 
            // nums[i] 可以接在 nums[j]之后（此题要求严格递增），
            // 此情况下最长上升子序列长度为 dp[j] + 1
            if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            // 否则则跳过
        }

        res = max(res, dp[i]);
    }

    return res;
}