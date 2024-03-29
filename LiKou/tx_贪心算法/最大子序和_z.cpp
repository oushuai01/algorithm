#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSubArray(vector<int>& nums) {
    // for(int i = 1; i < nums.size(); ++i){
    //     if(nums[i - 1] > 0){
    //         nums[i] = nums[i - 1] + nums[i];
    //     }
    // }
    // sort(nums.begin(),nums.end());
    // return nums[nums.size() - 1];


    int res = INT32_MIN;
    int count = 0;
    for(int i = 0; i < nums.size(); ++i){
        count += nums[i];
        if(count > res)
        res = count;
        if(count <= 0) count = 0;
    }
    return res;
    
}

int main(){
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(num);
}
