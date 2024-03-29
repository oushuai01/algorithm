#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//11.03


// 有重复元素
// 去重方法和 06_组合总和II 类似
vector<int> path;
vector<vector<int>> result;
void trackBack(int start, vector<int>& nums){
    result.push_back(path);

    if(start >= nums.size()) return;

    for(int i = start; i < nums.size(); i++){
        // 去除重复 层序去重
        if(i > start && nums[i] == nums[i - 1])
        continue;

        path.push_back(nums[i]);
        trackBack(i + 1, nums);
        path.pop_back();
    }

}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if(nums.size() == 0) return result;
    // 先排序
    sort(nums.begin(), nums.end());
    trackBack(0, nums);

    return result;
}
