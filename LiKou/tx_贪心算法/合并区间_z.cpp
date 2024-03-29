#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<int> msize(2);
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); ++i){
        if(intervals[i][0] < res.back()[1]){
           res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else{
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main(){

    
}
