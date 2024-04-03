#include <iostream>
#include <vector>
using namespace std;

// 2024-04-03

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty()) return {-1,-1};
    int l = 0, r = nums.size() - 1;
    int mid;
    // 拿到左边界第一个大于等于target
    while(l < r){
        mid = (l + r) / 2;
        // r 就是第一个大于等于target的索引
        if(nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if(nums[r] != target) return {-1,-1};

    int L = r;
    l = 0; r = nums.size() - 1;

    // 拿到右边界第一个大于等于target
    while(l < r){
        mid = (l + r + 1) / 2;
        if(nums[mid] <= target) l = mid;
        // r 就是最后一个大于等于 target 的索引
        else r = mid - 1;
    }

    // 善用两个模板进行左右边界筛选

    return {L, r};
}




int check(int mid){
    return 1;
}

// 模板1
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r)/2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
// 模板2
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = ( l + r + 1 ) /2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
