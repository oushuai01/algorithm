#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int res = 0;
    for(int i = 1; i < prices.size(); ++i){
        res += max(prices[i] - prices[i - 1], 0);
    }
    return res;
}

int main(){
    vector<int> price = {7,1,5,3,6,4};
    cout << maxProfit(price);

}