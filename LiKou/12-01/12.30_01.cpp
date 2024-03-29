#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i = 0; i  < nums.size() -1; i++){
        if(nums[i] == nums[i+1])
        return true;
    }
    return false;
}


int main()
{
    vector<int> arr= {1,1,1,3,3,4,3,2,4,2};
    cout << containsDuplicate(arr);
    return 0;
}
