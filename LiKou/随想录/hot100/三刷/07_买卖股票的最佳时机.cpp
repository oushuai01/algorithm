#include <iostream>
#include <vector>
using namespace std;
// 选择在最便宜的一天买入 (贪心)
int maxProfit(vector<int>& prices) {
    int cost = INT_MAX, profit = 0;

    for(int price : prices){
        cost = min(cost, price);
        profit = max(profit, price - cost);
    }

    return profit;
}