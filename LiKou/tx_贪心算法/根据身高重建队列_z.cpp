#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] > b[0])
    return a[0] > b[0];
    if(a[0] == b[0])
    return a[1] < b[1];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),cmp);
    list<vector<int>> Queue_list;
    for(int i = 0; i < people.size(); ++i){
        list<vector<int>>::iterator it =  Queue_list.begin();
        int pos = people[i][1];
        while(pos--){
            it++;
        }
        Queue_list.insert(it,people[i]);
    }
    return vector<vector<int>>(Queue_list.begin(),Queue_list.end());
}

int main(){

}