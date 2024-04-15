#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;

// 2024-04-15

int maxProduct(vector<int>& nums) {
    // 对于乘法，我们需要注意，负数乘以负数，会变成正数，所以解这题的时候我们需要维护两个变量，
    // 当前的最大值，以及最小值，最小值可能为负数，
    // 但没准下一步乘以一个负数，当前的最大值就变成最小值，而最小值则变成最大值了。
    int maxDp = nums[0];
    int minDp = nums[0];
    int p = nums[0];


    for(int i = 1; i < nums.size(); i++){
        int t = maxDp;
        maxDp = max(max(maxDp * nums[i], nums[i]), minDp * nums[i]);
        minDp = min(min(t * nums[i], nums[i]), minDp * nums[i]);
        p = max(p, maxDp);
    }

    return p;
}