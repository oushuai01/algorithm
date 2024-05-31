#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 也可以用摩尔投票
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
}