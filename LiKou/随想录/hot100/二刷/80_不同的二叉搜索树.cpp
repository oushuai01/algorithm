#include <iostream>
#include <vector>
using namespace std;

// 2024-04-10

int numTrees(int n) {
   vector<int> dp(n + 1, 0);
   // dp表示 1到i为节点组成的二叉搜索树的个数为dp[i]
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            // dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量] 
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }

    return dp[n];
}  