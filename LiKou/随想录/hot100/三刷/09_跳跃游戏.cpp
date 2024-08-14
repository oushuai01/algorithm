#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int max_dis = 0;
    // 计算最大可覆盖范围
    for(int i = 0; i <= max_dis; i++){
        max_dis = max(max_dis, i + nums[i]);
        if(max_dis >= (nums.size() - 1)) return true;
    }

    return false;
}