#include <iostream>
#include <vector>
using namespace std;

// 2024-03-29
vector<int> path;
vector<vector<int>> result;
void backTrack(vector<int>& nums, int start){
    result.push_back(path);

    if(start >= nums.size()) return;

    for(int i = start; i < nums.size(); i++){
        path.push_back(nums[i]);
        backTrack(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    if(nums.size() == 0) return result;
    backTrack(nums, 0);
    return result;
}
