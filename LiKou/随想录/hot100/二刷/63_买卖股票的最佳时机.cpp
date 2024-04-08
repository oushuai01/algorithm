#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2024-04-06

int maxProfit(vector<int>& prices) {
    // 选择在最便宜的一天买入 (贪心)
    int cost = INT_MAX, profit = 0;
    for(int price : prices){
        cost = min(cost, price);
        profit = max(profit, price - cost);
    }

    return profit;
}