 #include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
 
 
 
 int main(){
 int N;
  cin >> N;
  vector<int> gaodu(N,0);
  vector<int> max_gaodu(N,0);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
        gaodu[j] = gaodu[j] + 1;
        max_gaodu[j] = max(max_gaodu[j],gaodu[j]);
        if(j == i)
        gaodu[j] = 0;
    }
  }
  for(int i = N - 2; i >= 0; --i){
    for(int j = 0; j < N; ++j){
        gaodu[j] = gaodu[j] + 1;
        max_gaodu[j] = max(max_gaodu[j],gaodu[j]);
        if(j == i)
        gaodu[j] = 0;
    }
  }
  for(int i = 1; i < N; ++i){
    for(int j = 0; j < N; ++j){
        gaodu[j] = gaodu[j] + 1;
        max_gaodu[j] = max(max_gaodu[j],gaodu[j]);
        if(j == i)
        gaodu[j] = 0;
    }
  }
  for(int i = 0; i < N; ++i){
    cout << max_gaodu[i] << endl;
  }




// 有更好的算法   找规律
/*
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) 
    cout<<max(i-1,n-i)*2<<endl;
*/
 }