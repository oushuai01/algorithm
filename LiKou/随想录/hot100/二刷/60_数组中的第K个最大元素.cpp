#include <iostream>
#include <vector>
using namespace std;

// 2024-04-05

int quickSelect(vector<int>& nums, int k){
    // 随机选取基数
    int pivot = nums[rand() % nums.size()];

    // 将大于、小于、等于pivot的元素划分为 big 、small 、 equal
    vector<int> big, small, equal;

    for(auto num : nums){
        if(num > pivot) big.push_back(num);
        else if(num < pivot) small.push_back(num);
        else equal.push_back(num);
    }

    // 第 k 大的元素在 big 中 递归划分
    if(k <= big.size()){
        return quickSelect(big, k);
    }

    // 第 k 大的元素在 small 中 递归划分
    if(nums.size() - small.size() < k){
        return quickSelect(small, small.size() - (nums.size() - k));
    }

    // 第 k 大元素在 equal 中，直接返回 pivot
    return pivot;
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, k);
}



int main(){
    vector<int> nums  = {3,2,1,5,6,4};
    int k = 2;
    cout << findKthLargest(nums, k);
}