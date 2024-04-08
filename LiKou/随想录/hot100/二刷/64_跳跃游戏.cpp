#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2024-04-06

bool canJump(vector<int>& nums) {
    if(nums.size() == 1) return true;
    // 计算最大可覆盖范围
    int cover = 0;
    for(int i = 0; i <= cover; i++){ // 注意这里是小于等于cover
        cover = max(cover, nums[i] + i);
        if(cover >= (nums.size() - 1)) return true;
    }

    return false;
}