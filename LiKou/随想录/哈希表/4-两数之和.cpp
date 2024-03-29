#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

 vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> unmap;
    for(int i = 0; i < nums.size(); ++i){
        if(unmap.find(target - nums[i]) != unmap.end()){
            return {i,unmap[target - nums[i]]};
        }
        unmap.insert(pair<int,int>(nums[i],i));
    }
    return {};

 }

int main(){



    return 0;
}