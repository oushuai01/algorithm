#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//10.30

vector<vector<int>> result;
vector<int> path;
void backtrack(vector<int> &candidates, int start, int sum, int target){
    if(sum > target)
    return;

    if(sum == target){
        result.push_back(path);
        return;
    }

    for(int i = start; i < candidates.size() && sum + candidates[i] <= target; i++){
        //去重  表示同一层使用过了
        if(i > start && candidates[i] == candidates[i - 1])
        continue;
        path.push_back(candidates[i]);
        backtrack(candidates, i + 1, sum + candidates[i], target);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if(candidates.size() == 0) return result;
    //排序
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, 0, 0, target);

    return result;
}