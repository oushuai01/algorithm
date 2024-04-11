#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
// 2024-04-11


// 回溯
int count_ = 0;
void backTrack(vector<int>& nums, int target, int start){
    if(nums.size() == start){
        if(target == 0) 
        count_++;

        return;
    }

    backTrack(nums, target - nums[start], start + 1);
    backTrack(nums, target + nums[start], start + 1);

}


// 转换成 0 1 背包问题

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int num : nums){
        sum += num;
    }

    int right = (sum + target);
    if(right % 2 != 0) return false;

    right = right / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(right + 1, 0));

    // 初始化 重量为j的背包装重量为j的方法为1
    if(nums[0] <= right)
    dp[0][nums[0]] = 1;
    // 初始化 重量为0的背包装重量为j的方法为1 因为它可以选择不装
    // 如果有0
    int numZeros = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            numZeros++;
        }
        dp[i][0] = pow(2, numZeros);
    }

    for(int i = 1; i < nums.size(); i++){
        for(int j = 1; j <= right; j++){
            // dp[i - 1][j] 表示不放 i    
            // dp[i - 1][j - nums[i]]  表示放 i
            if(j < nums[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
        }
    }

    return dp[nums.size() - 1][right];
}



