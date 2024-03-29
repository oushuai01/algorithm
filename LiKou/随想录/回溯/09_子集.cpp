/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-01 15:15:57
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-03 15:09:11
 * @FilePath: \algorithm\LiKou\随想录\回溯\09_子集.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//11.01

//没有重复元素

vector<vector<int>> result;
vector<int> path;
void backtrack(vector<int>& nums, int start){
    //放在最前面 否则会漏掉自己
    result.push_back(path);

    if(start >= nums.size()) return;

    for(int i = start; i < nums.size(); i++){
        path.push_back(nums[i]);
        backtrack(nums, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    if(nums.size() == 0) return result;
    backtrack(nums, 0);
    return result;
}