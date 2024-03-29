#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxSubArray(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++){
        if(nums[i-1] > 0){
            nums[i] = nums[i-1] + nums[i];
        }
    }
    return *max_element(nums.begin(),nums.end());

}

int main()
{
    vector<int> arr= {-2};
    cout << maxSubArray(arr);
    return 0;
}