#include <iostream>
#include <vector>

using namespace std;

// 保留相同k个数
int work(vector<int>& nums, int k){
    int len = 0;
    // 遍历整个数组
    for(auto num : nums){
        // 保留前k个  以及保留当前位置的前面 k 个元素不同的数
        if(len < k || nums[len - k] != num)
            nums[len++] = num;
        
    }

    return len;
}

int removeDuplicates(vector<int>& nums) {
    return work(nums, 2);
}