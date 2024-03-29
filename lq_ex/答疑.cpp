#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
}

int main(){
    int num;
    cin >> num;
    vector<vector<int>> arr(num,vector<int>(3));
    int push_, question_, pop_;
    for(int i = 0; i < num; ++i){
        cin >> push_ >> question_ >> pop_;
        arr[i][0] = push_;
        arr[i][1] = question_;
        arr[i][2] = pop_;
    }
    sort(arr.begin(),arr.end(),cmp);
    int min_time = 0;
    for(int i = 0; i < num; ++i){
        min_time += (arr[i][0] + arr[i][1] + arr[i][2]) * (num - i -1);
    }
    for(int i = 0; i < num; ++i){
        min_time += arr[i][0] + arr[i][1];
    }
    cout << min_time;


}