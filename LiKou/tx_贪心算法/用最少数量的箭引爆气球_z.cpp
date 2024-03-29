#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[0] <= b[0];
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end(),cmp);
    int count = 1;
    int back_min = points[0][1];
    for(int i = 1; i < points.size(); ++i){
        if(points[i][0] > back_min){
            count++;
            back_min = points[i][1];
        }
    }
    return count;
}

int main(){
    return 0;

}