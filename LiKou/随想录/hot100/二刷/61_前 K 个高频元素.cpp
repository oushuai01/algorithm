#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 2024-04-05

static bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.second > b.second;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> umap;
    for(int num : nums){
        umap[num]++;
    }
    vector<pair<int,int>> vec;
    for(auto pair_ : umap){
        vec.push_back(pair_);
    }

    sort(vec.begin(), vec.end(), cmp);

    vector<int> result;
    for(int i = 0; i < k; i++){
        result.push_back(vec[i].first);
    }

    return result;
    
}