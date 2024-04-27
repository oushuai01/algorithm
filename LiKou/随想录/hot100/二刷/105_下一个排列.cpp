#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pos = nums.size() - 1;
    // 找到第一个不是升序的数字(从后往前)
    while (pos > 0 && nums[pos] <= nums[pos - 1])
        pos--;
    reverse(nums.begin() + pos, nums.end());  //逆序
    if (pos > 0){
        int start = pos;
        for (; start < nums.size(); start++){ //寻找第一个大于nums[pos - 1]的数
            if (nums[start] > nums[pos - 1]){
                swap(nums[start], nums[pos - 1]); //交换
                break;
            }
        }
    }
}