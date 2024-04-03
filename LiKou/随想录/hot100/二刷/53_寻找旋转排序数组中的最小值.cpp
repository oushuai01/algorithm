#include <iostream>
#include <vector>
using namespace std;

// 2024-04-03

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    if(nums[l] < nums[r]) return nums[0];
    // 找左边界 第一个小于nums[0]的值
    while(l < r){
        int mid = (l + r) / 2;
        if(nums[mid] < nums[0]) r = mid;
        else l = mid + 1;
    }

    return nums[r];
}