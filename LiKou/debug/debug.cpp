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
    // 反转前index_个数据
    for(int i = 0; i < index_ / 2; i++)
    swap(nums[i], nums[index_ - i - 1]);
    // 反转index_后的数据
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

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate(nums, k);
}