#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 3.5
// https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked

vector<vector<string>> groupAnagrams(vector<string>& strs){
    vector<vector<string>> res;
    unordered_map<string, vector<string>> umaps;
    for(auto str  : strs){
        auto data = str;
        //排序str 使得字母都是从小到大
        sort(str.begin(), str.end());
        umaps[str].push_back(data);
    }

    for(auto umap : umaps){
        res.push_back(umap.second);
    }

    return res;
}