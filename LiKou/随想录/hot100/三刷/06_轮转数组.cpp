#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<int>& nums, int k) {
    int size_ = nums.size();
    int index_ = k % nums.size();
    // 整体反转
    for(int i = 0; i < nums.size() /2 ; i++){
        swap(nums[i], nums[size_ - i - 1]);
    }
    // 反转前 index_ 个数据
    for(int i = 0; i < index_ / 2; i++)
    swap(nums[i], nums[index_ - i - 1]);
    // 反转 index_ 后的数据
    for(int i = index_; i < index_ + (size_ - index_) / 2; i++)
    swap(nums[i], nums[size_ + index_ - i - 1]);

    // 也可以使用api 来完成
    // // 整体反转
    // reverse(nums.begin(), nums.end());

    // // 反转前k个
    // reverse(nums.begin(), nums.begin() + k);

    // // 反转剩余的
    // reverse(nums.begin() + k, nums.end());

}