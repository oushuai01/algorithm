#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 2024-04-21
// https://leetcode.cn/problems/longest-common-subsequence/solutions/963588/zui-chang-gong-gong-zi-xu-lie-tu-jie-dpz-6mvz
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    // 状态表示： 定义 f[i][j]表示字符串text1的[1,i]区间和字符串text2的[1,j]区间的最长公共子序列长度（下标从1开始）。
    vector<vector<int>> dp(n + 1,  vector<int>(m + 1, 0));
    dp[n][0] = 0;
    dp[0][m] = 0;

    for(int i = 1; i <= n; i++){
        for(int j  = 1; j <= m; j++){
            if(text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else if(text1[i] != text2[j]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}