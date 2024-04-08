#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2024-04-06

int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;

    int ans = 0;   // 记录步数
    int curDistance  = 0;  // 当前最远距离
    int nextDistance = 0;  // 下一步最远距离

    for(int i = 0; i < nums.size(); i++){
        // 更新最远距离
        nextDistance = max(nextDistance, i + nums[i]);

        if(i == curDistance){  // 遇到当前覆盖最远距离下标
            ans++;             // 需要走下一步
            curDistance = nextDistance; // 更新当前覆盖最远距离下标（相当于加油了）
            if(nextDistance > nums.size() - 1) break; // 当前覆盖最远距到达集合终点，不用做ans++操作了
        }
    }

    return ans;

}