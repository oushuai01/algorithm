/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-03 15:11:08
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-03 15:49:09
 * @FilePath: \algorithm\LiKou\随想录\回溯\11_递增子序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//11.03
vector<int> path;
vector<vector<int>> result;

void trackBack(int start, vector<int>& nums){
    if(path.size() >= 2)
        result.push_back(path);

    if(start >= nums.size())
    return;

    unordered_set<int> uset;
    for(int i = start; i < nums.size(); i++){
        // 不能使用这个  因为不能将数组进行排序
        // if(i > start && nums[i] == nums[i - 1])
        // continue;
        // (非空 && 不是递增)   或者   找到重复的了
        if((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
        continue;

        uset.insert(nums[i]);
        path.push_back(nums[i]);
        trackBack(i + 1, nums);
        path.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    if(nums.size() == 0)
    return result;

    trackBack(0, nums);
    return result;
}


int main(){
    vector<int> nums  = {1, 2, 3};
    vector<vector<int>> res = findSubsequences(nums);
    for(auto elements : res){
        for(auto element : elements)
        cout << element << " ";
        cout << "|";
    }
}