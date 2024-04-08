#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 2024-04-05

int largestRectangleArea(vector<int>& heights) {
    stack<int> sta;
    int res = 0;
    // 前后插入0  
    // 后补0是为了防止低调递增数组  到最后还无法进行处理
    // 前补0是为了防止前2个数无法完成计算

    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    // 单调递减栈
    sta.push(0);
    for(int i = 1; i < heights.size(); i++){
        while(heights[i] < heights[sta.top()]){  // 找到第一个小于它的值
            int mid = sta.top();
            sta.pop();
            int w = i - sta.top() - 1;
            int h = heights[mid];
            res = max(res, w * h);
        }
        sta.push(i);
    }
    return res;

}