#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// 2024-04-22
// https://leetcode.cn/problems/edit-distance/solutions/1237735/bian-ji-ju-chi-tu-jie-dp-zui-qing-xi-yi-abfgl
int minDistance(string word1, string word2) {
   int n = word1.size();
    int m = word2.size();
    word1 = " " + word1;  //添加空格 为了让他至少有一个字符 下面的遍历也是从1开始的
    word2 = " " + word2;
    // f[i][j] 表示将 word1 的前 i 个字符变成 word2 的前 j 个字符所需要进行的最少操作次数。
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // 初始化
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int i = 0; i <= m; i++) dp[0][i] = i;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;  // 添加或者删除
            if(word1[i] == word2[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);  // 替换
        }
    }

    return dp[n][m];

}