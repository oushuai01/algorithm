#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;


    int ans = 0;     // 步数
    int curDistance = 0;  // 当前最远距离
    int nextDistance = 0; // 下一步最远距离


    for(int i = 0; i < nums.size(); i++){
        // 更新最远距离
        nextDistance = max(nextDistance, i + nums[i]);

        if(i == curDistance){
            ans++;
            curDistance = nextDistance;
            if(nextDistance >= (nums.size() - 1)) break;
        }
    }

    return ans;

}