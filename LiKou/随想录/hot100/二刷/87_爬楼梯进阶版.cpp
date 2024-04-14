//https://kamacoder.com/problempage.php?pid=1067
// 卡码网KamaCoder


// 2024-04-14

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    std::vector<int> dp(n + 1, 0) ;
    dp[0] = 1;
    
    for(int j = 1; j <= n; j++){  // 背包
        for(int i = 1; i <= m; i++){  // 物品
            // 求排列  先跳后跳 有先后之分
            if(j >= i) dp[j] += dp[j - i];
        }
    }
    
    cout << dp[n];
}


/*
在求装满背包有几种方案的时候，认清遍历顺序是非常关键的。

如果求组合数就是外层for循环遍历物品，内层for遍历背包。

如果求排列数就是外层for遍历背包，内层for循环遍历物品。

*/