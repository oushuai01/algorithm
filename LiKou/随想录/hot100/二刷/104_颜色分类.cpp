#include <iostream>
#include <vector>
using namespace std;


// 2024-04-24
void sortColors(vector<int>& nums) {
    // 三指针
    int l = 0, r = nums.size() - 1;

    for(int i = 0; i <= r; i++){
        if(nums[i] == 0) swap(nums[l++], nums[i]);
        else if(nums[i] == 2) swap(nums[r--], nums[i--]);
    }
}