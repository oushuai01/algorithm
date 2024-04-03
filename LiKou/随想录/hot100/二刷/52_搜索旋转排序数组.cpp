#include <iostream>
#include <vector>
using namespace std;

// 2024-04-03

int search(vector<int>& nums, int target) {
    // 找到分界点
    int l = 0, r = nums.size() - 1;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(nums[mid] >= nums[0]) l = mid;
        // 找到最后一个大于nums[0]的值
        else r = mid - 1;
    }

    // 判断在哪个区间
    if(target >= nums[0]) l = 0;
    else {
        l = r + 1;
        r = nums.size() - 1;
    }
    // 在这段区间找目标值
    while(l < r){
        int mid = (l + r) / 2;
        if(nums[mid] >= target) r = mid;
        else l = mid + 1;
    }

    if(nums[r] == target) return r;

    return -1;

}