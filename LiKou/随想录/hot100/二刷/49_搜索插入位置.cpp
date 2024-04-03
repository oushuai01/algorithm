#include <iostream>
#include <vector>
using namespace std;
// 2024-04-02

int search(vector<int>& nums, int target, int left, int right){
    int mid = (right + left) / 2;

    //左闭右闭
    if(nums[mid] == target || (nums[mid] > target && nums[mid - 1] < target)) return mid;
    else if(nums[mid] < target && nums[mid + 1] > target) return mid + 1;


    if(nums[mid] > target) {
        mid = search(nums, target, left, mid - 1);
    }
    else if(nums[mid] < target){
        mid = search(nums, target, mid + 1, right);
    }

    return mid;

}

int searchInsert(vector<int>& nums, int target) {
	if(target > nums[nums.size() - 1]) return nums.size();
	if(target < nums[0]) return 0;
    return search(nums, target, 0, nums.size());
}


int searchInsert_(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = (right + left) / 2;
    while(left <= right){
        if(nums[mid] == target)
        return mid;
        else if(nums[mid] < target)
        left = mid + 1;
        else if(nums[mid] > target)
        right = mid - 1;
    }

    // 没找到left就是适合它插入的地方
    return left;
}

