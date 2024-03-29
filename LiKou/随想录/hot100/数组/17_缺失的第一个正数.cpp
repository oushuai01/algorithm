#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if(nums[0] > 1 || nums[nums.size() - 1] < 1)
    return 1;
    
    // debug
    // for(int num : nums)
    // cout << num << " ";
    // cout << endl;
    
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] < 0)
        continue;
        if(nums[i] - nums[i - 1] > 1){
            if(nums[i] >= 1 && nums[i - 1] >= 1){
                return nums[i - 1] + 1;
            }
            else if(nums[i] > 1 && nums[i - 1] < 1)
            return 1;
        }
    }

    return nums[nums.size() - 1] + 1;
}

int main(){
    vector<int> vec = {1,3,1,1,1,1};
    cout << firstMissingPositive(vec);
}