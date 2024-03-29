#include <iostream>
#include <vector>
using namespace std;


int climbStairs(int n) {
    vector<int> dp(n);
    if(n <= 2) return n;
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i < n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];

    // if(n <= 2) return n;
    // return climbStairs(n-1) + climbStairs(n-2);

}

int main(){
    cout << climbStairs(45);
    return 0;
}