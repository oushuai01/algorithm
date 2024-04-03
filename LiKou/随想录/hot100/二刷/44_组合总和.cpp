#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
vector<vector<int>> result;
// 2024-04-01
void backTrack(vector<int>& candidates, int target, int start){
    if(target == 0){
        result.push_back(path);
        return;
    }else if(target < 0) return;

    // 不能有重复的数字  就是数字一样但顺序不一样的要剔除  用start
    for(int i = start; i < candidates.size(); i++){
        path.push_back(candidates[i]);
        // 这里的 start 变成 i
        backTrack(candidates, target - candidates[i], i);
        path.pop_back();
    }

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(candidates.size() == 0) return result;

    backTrack(candidates, target, 0);

    return result;
}