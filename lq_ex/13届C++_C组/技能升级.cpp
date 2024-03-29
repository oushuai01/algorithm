#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100010;
bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first != b.first)
    return a.first > b.first;
    else
    return a.second < b.second;
}
bool cheak(pair<int,int> &front_,pair<int,int> &back_){
    if(front_.first < back_.first)
    return true;
    else if(front_.first == back_.first){
        if(front_.second > back_.second)
        return true;
    }
    else
    return false;
}

//暴力只能过4个
int main(){
    vector<pair<int,int>> vec(N , pair<int,int>(0,0));
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    long long sum = 0; 
    long long index_ = 1;
    while(m--){
        sort(vec.begin() + 1,vec.begin() + n  + 1, cmp);
        if(vec[index_].first <= 0) break;
        sum += vec[index_].first;
        vec[index_].first -= vec[index_].second;
        if(vec[index_].first <= 0) vec[index_].first = 0;
    }
    cout << sum;

}