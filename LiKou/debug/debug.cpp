#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int count_ = 0;
void backTrack(vector<int>& nums, int target, int start){
    if(nums.size() == start){
        if(target == 0) 
        count_++;

        return;
    }

    
    backTrack(nums, target - nums[start], start + 1);
    backTrack(nums, target + nums[start], start + 1);
    

}


int findTargetSumWays(vector<int>& nums, int target) {
    backTrack(nums, target, 0);
    return count_;
}

int main(){
    vector<int>nums = {1,1,1,1,1};
    int target = 3;

    cout << findTargetSumWays(nums, target);
}