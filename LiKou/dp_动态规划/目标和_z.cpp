#include <vector>
#include <iostream>
using namespace std;

int dfs(vector<int>& nums, int target, int pos, int cur){
    if(pos == nums.size()){
        return cur == target ? 1 : 0;
    }
    int right = dfs(nums, target, pos + 1 , cur + nums[pos]);
    int left = dfs(nums, target, pos + 1 , cur - nums[pos]);
    return right + left;
}

int findTargetSumWays(vector<int>& nums, int target){
    return dfs(nums, target, 0 , 0);
}


int main(){
    vector<int> vc = {1,1,1,1,1};
    cout << findTargetSumWays(vc,3);
    return 0;
}