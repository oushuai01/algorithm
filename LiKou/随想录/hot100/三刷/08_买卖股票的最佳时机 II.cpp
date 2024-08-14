#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;

    for(int i = 1; i < prices.size(); i++){
        int temp = prices[i] - prices[i - 1];
        if(temp > 0) profit += temp;
    }

    return profit;
}



