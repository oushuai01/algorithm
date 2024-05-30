#include <iostream>
#include <vector>

using namespace std;

/*

一个指针 fast 进行数组遍历，另外一个指针 slow 指向有效数组的最后一个位置。
只有当 fast 所指向的值和 slow 不一致（不重复），才将 fast 的值添加到 slow 的下一位置。

*/
int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;

    int slow = 0;

    for(int fast = 0; fast < nums.size(); fast++){
        if(nums[slow] != nums[fast]){
            nums[++slow] = nums[fast];
        }
    }

    return slow + 1;
}


