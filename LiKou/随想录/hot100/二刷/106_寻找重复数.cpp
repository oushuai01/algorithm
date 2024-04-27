#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // 想象成链表环
    int fast = 0, slow = 0;
    while(true){
        fast = nums[nums[fast]];
        slow = nums[slow];
        if(fast == slow)
        break;
    }

    int finder = 0;
    while(true){
        finder = nums[finder];
        slow = nums[slow];
        if(finder == slow)
        break;
    }

    return slow;
}