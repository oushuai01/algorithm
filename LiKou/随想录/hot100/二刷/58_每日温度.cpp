#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 2024-04-05
// https://leetcode.cn/problems/daily-temperatures/solutions/71433/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int temperatures_size = temperatures.size();
    vector<int> res(temperatures_size, 0);
    stack<int> sta;

    for(int i = 0; i < temperatures_size; i++){
        while(!sta.empty() && temperatures[i] > temperatures[sta.top()]){
            int n = sta.top();
            sta.pop();
            res[n] = i - n;
        }
        sta.push(i);
    }

    return res;
}