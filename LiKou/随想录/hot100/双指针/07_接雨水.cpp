#include <iostream>
#include <vector>
using namespace std;


int trap(vector<int>& height) {
    int sum = 0;
    for(int i = 0; i < height.size(); i++){
        if(i == 0 || i == height.size() - 1) continue;

        int lHeight = height[i];
        int rHeight = height[i];

        // 找到左边比自己高的
        for(int l = 0; l < i; l++){
            if(height[l] > lHeight)
            lHeight = height[l];
        }

        // 找到右边比自己高的
        for(int r = i + 1; r < height.size(); r++){
            if(height[r] > lHeight)
            rHeight = height[r];
        }
        // 核心
        int h = min(lHeight, rHeight) - height[i];
        if(h > 0) sum += h;
    }

    return sum;
}


// 双指针优化
int trap(vector<int>& height) {
    vector<int> maxLeft(height.size(), 0);
    vector<int> maxRight(height.size(), 0);
    int sum = 0;

    maxLeft[0] = height[0];
    for(int i = 1; i < height.size() - 1; i++){
        maxLeft[i] = max(height[i], maxLeft[i - 1]);
    }

    maxRight[height.size() - 1] = height[height.size() - 1];
    for(int i = height.size() - 2; i > 0; i--){
        maxRight[i] = max(height[i], maxRight[i + 1]);
    }

    for(int i = 1; i < height.size() - 1; i++){
        int leftmax = maxLeft[i];
        int rightmax = maxRight[i];

        // 核心
        int h = min(leftmax, rightmax) - height[i];
        if(h > 0) sum += h;
    }

    return sum;

}

// 单调栈也可以 https://programmercarl.com/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.html#%E6%80%9D%E8%B7%AF