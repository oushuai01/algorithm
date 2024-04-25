#include <iostream>
#include <vector>
using namespace std;

// 2024-04-24
// https://leetcode.cn/problems/majority-element/solutions/2362000/169-duo-shu-yuan-su-mo-er-tou-piao-qing-ledrh
int majorityElement(vector<int>& nums) {
    // 摩尔排序
    int condition = 0, vote = 0;

    for(int i = 0; i < nums.size(); i++){
        if(vote == 0) condition = nums[i];
        if(nums[i] == condition) vote++;
        else vote--;
    }

    return condition;
}