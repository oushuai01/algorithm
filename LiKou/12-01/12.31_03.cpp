
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> sum;
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = i + 1; j  < nums.size(); j++){
            if((nums[i] + nums[j]) == target){
                sum.push_back(i);
                sum.push_back(j);
                break;
            }
        }
    }
    return sum;
}
vector<int> twoSum2(vector<int>& nums, int target) {
    map<int,int> mp;
    for(int i = 0; i < nums.size(); i++)
        mp.insert(pair<int,int>(nums[i],i));
    for(int i = 0; i < nums.size(); i++){
        if((mp.count(target - nums[i]) > 0) && (mp[target - nums[i]] != i)){
            return {i,mp[target - nums[i]]};
        }
    }
    return {-1,-1};
}
int main()
{
    vector<int> num = {2,7,11,15};
    int target = 9;
    vector<int> res =twoSum2(num,target);
    cout << res[0] << " " << res[1];
    return 0;
}
