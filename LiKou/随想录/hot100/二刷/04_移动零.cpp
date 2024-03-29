#include <vector>
using namespace std;

// 双指针 ： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
void moveZeroes(vector<int>& nums) {
    int left = 0;
    int right = 0;
    int size_ = nums.size();
    while(right < size_){
        if(nums[right]){
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}