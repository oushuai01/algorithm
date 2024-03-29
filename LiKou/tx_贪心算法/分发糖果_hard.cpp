#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int>& ratings) {
        int people_size = ratings.size();
    int total_candy = 0;
    vector<int> candy_(people_size,1);
    //从前往后
    for(int i = 1; i < people_size; ++i){
        if(ratings[i] > ratings[i - 1])
        candy_[i] = candy_[i - 1] + 1;
    }
    //从后往前
    for(int i = people_size - 1; i > 0; --i){
        if(ratings[i - 1] > ratings[i]){
            // if(candy_[i - 1] > candy_[i])
            // continue;
            // else
            // candy_[i - 1] = candy_[i] + 1;
            candy_[i - 1] = max(candy_[i - 1], candy_[i] + 1);
        }
    }
    for(int i = 0; i < people_size; ++i){
        total_candy += candy_[i];
    }
    return total_candy;

}

int main(){
    vector<int> candy_people = {1,3,4,5,2};
    cout << candy(candy_people);
    return 0;

}