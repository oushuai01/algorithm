#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices) {
    int size = prices.size();
    if(size == 0)
    return 0;
    int minprices = prices[0];
    int maxprofit = 0;
    for(int i = 1; i < size; i++){
        minprices = min(minprices,prices[i]);
        maxprofit = max(maxprofit,prices[i] - minprices);
    }
    return maxprofit;

}

int main(){
    vector<int> v1 = {7,1,5,3,6,4};
    cout << maxProfit(v1);
}