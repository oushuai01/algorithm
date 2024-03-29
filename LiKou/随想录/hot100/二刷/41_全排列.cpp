#include <iostream>
#include <vector>
using namespace std;
// 回溯

// 2024-03-29
vector<int> path;
vector<vector<int>> result;
void trackBack(vector<int>& nums, vector<bool>& used){
    if(path.size() == nums.size()){
        result.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        // 记录使用过的元素
        if(used[i] == true) continue;
        used[i] = true;

        path.push_back(nums[i]);
        trackBack(nums, used);
        path.pop_back();
        used[i] = false;

    }
}
vector<vector<int>> permute(vector<int>& nums){
    if(nums.size() == 0) return result;
    vector<bool> used(nums.size(), false);
    trackBack(nums, used);

    return result;
}