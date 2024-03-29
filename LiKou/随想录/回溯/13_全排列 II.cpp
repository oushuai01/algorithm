/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-06 14:54:01
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-06 15:33:23
 * @FilePath: \algorithm\LiKou\随想录\回溯\12_全排列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//11.06
vector<int> path;
vector<vector<int>> result;
void trackBack(vector<int>& nums, vector<bool> used){
    if(path.size() == nums.size()){
        result.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        // 去除同一层重复元素   
        // used[i - 1] == false 是树层上去重           used[i - 1] == true 是树枝上去重
        // used[i - 1] == false 这个条件不能省略
        if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        continue;

        if(used[i] == true) continue;
        used[i] = true;
        path.push_back(nums[i]);
        trackBack(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    if(nums.size() == 0) return result;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    trackBack(nums, used);

    return result;

}