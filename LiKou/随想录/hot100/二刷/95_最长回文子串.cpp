#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 2024-04-16

string longestPalindrome(string s) {
    // dp 数组含义为 布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int maxLen = 0;
    string res = "";
    for(int i = s.size() - 1; i >= 0; i--){
        for(int j = i; j < s.size(); j++){
            if(s[i] != s[j]) dp[i][j] = false;
            else if(s[i] == s[j]){
                if(j - i <= 1) dp[i][j] = true;
                // 由于使用 dp[i + 1][j - 1] 来更新 dp[i][j] 所以遍历顺序要从下往上
                // 从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。
                else if(dp[i + 1][j - 1]) dp[i][j] = true;
            }
            if(dp[i][j]){
                if(j - i + 1 > maxLen){
                    maxLen = max(maxLen, j - i + 1);
                    res = s.substr(i, maxLen);
                }
                
            }
        }
    }

    return res;
}