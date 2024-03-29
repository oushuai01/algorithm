#include <iostream>
#include <vector>

using namespace std;
//左闭右闭
//[left,right]
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int middle = left + (right - left) / 2;
        if(nums[middle] > target){
            right = middle - 1;
        }
        else if(nums[middle] < target){
            left = middle + 1;
        }
        else if(nums[middle] == target){
            return middle;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = -1;
    cout << search(nums,target);
    return 0;
}