#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 3.5
// https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-100-liked


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> umap;
    for(int i = 0; i < nums.size(); i++){
        if(umap.find(target - nums[i]) != umap.end()){
            return {i, umap[target - nums[i]]};
        }

        // map类型的插入 
        // 1  insert(pair<string,int>("apple",2));
        // 2  insert(map<string, int>::value_type("orange",3));
        // 使用数值作为key 下标作为value
        umap.insert(pair<int,int>(nums[i], i));
    }
    return {};

}