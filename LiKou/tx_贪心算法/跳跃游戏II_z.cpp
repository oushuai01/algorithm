#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    if(nums.size() == 1)
    return 0;
    int curDistance  = 0;
    int nextDistance = 0;
    int count = 0;
    for(int i = 0; i < nums.size(); ++i){
       nextDistance = max(i + nums[i], nextDistance);
       if(i == curDistance){
        if(curDistance < nums.size() - 1){
            count++;
            if(nextDistance > curDistance)
            curDistance = nextDistance;
        }
        else
        break;
       }
    }
    return count;
}

int main(){
    vector<int> num = {2,3,1,1,4};
    cout << jump(num);
    return 0;
}