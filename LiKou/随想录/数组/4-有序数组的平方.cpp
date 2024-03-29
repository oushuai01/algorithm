#include <iostream>
#include <vector>
using namespace std;
//双指针
vector<int> sortedSquares(vector<int>& nums){
    int size_ = nums.size();
    vector<int> re_nums(size_);
    int k = size_ - 1;
    for(int i = 0,j = size_ - 1;i <= j;){
        if(nums[i] * nums[i] > nums[j] * nums[j]){
            re_nums[k] = nums[i] * nums[i];
            i++;
        }
        else if(nums[i] * nums[i] <= nums[j] * nums[j]){
            re_nums[k] = nums[j] * nums[j];
            j--;
        }
        k--;
    }
    return re_nums;
}

int main(){

    vector<int> nums = {-4,-1,0,3,10};
    vector<int> re_nums = sortedSquares(nums);
    for (auto &&i : re_nums)
    {
        cout << i << " ";
    }
    




    return 0;
}