#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a, int &b){
    return a < b;
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    if(g.empty() || s.empty())
    return 0;
    //sort 默认升序排列
    sort(g.begin(),g.end(),cmp);
    sort(s.begin(),s.end(),cmp);
    //先满足大的
    int index = s.size() - 1;
    int count = 0;
    for(int i = g.size() - 1; i >= 0; --i){
       if(index >= 0 && (s[index] >= g[i])){
        count++;
        index--;
       }
    }

    //先满足小的
    // int index = 0;
    // int count = 0;
    // for(int i = 0; i < s.size(); ++i){
    //     if(index < g.size() && s[i] >= g[index]){
    //         index++;
    //         count++;
    //     }
    // }
    return count;
}

int main(){
    vector<int> g = {10,9,8,7}, s = {5,6,7,8};
    cout << findContentChildren(g,s);
    return 0;
}