/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-27 09:47:36
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-27 10:13:49
 * @FilePath: \algorithm\LiKou\随想录\回溯\05_组合总和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//10.27

using namespace std;

vector<vector<int>> result;
vector<int> path;

void combinationSumTrack(vector<int>& candidates, int start, int sum, int target){
    if(sum == target && result.size() < 150){
        result.push_back(path);
        return;
    }

    //不能有重复的数字  就是数字一样但顺序不一样的要剔除  用start
    //加了剪枝的操作 sum + candidates[i] <= target   加这个限制条件就先要排序
    for(int i = start; i < candidates.size() && sum + candidates[i] <= target; i++){
        path.push_back(candidates[i]);
        combinationSumTrack(candidates, i, sum + candidates[i], target);
        path.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(candidates.size() == 0)
    return result;
    sort(candidates.begin(), candidates.end());
    combinationSumTrack(candidates, 0, 0, target);
    return result;
}

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> vec = combinationSum(candidates, target);
    for(vector<int> nums : vec){
        for(int num : nums)
        cout << num << " ";
        cout << "|";
    }
}





//不进行剪枝的写法
void combinationSumTrack(vector<int>& candidates, int start, int sum, int target){
    if(sum == target && result.size() < 150){
        result.push_back(path);
        return;
    }
    if(sum > target)
    return;
    
    //不能有重复的数字  就是数字一样但顺序不一样的要剔除  用start
    for(int i = start; i < candidates.size(); i++){
        path.push_back(candidates[i]);
        combinationSumTrack(candidates, i, sum + candidates[i], target);
        path.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(candidates.size() == 0)
    return result;
    combinationSumTrack(candidates, 0, 0, target);
    return result;
}