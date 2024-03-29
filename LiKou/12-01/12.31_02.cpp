
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canJump(vector<int>& nums) {
    int index = nums.size() - 1;
    if(index == 0) return true;
    int cover = 0;
    for(int i = 0; i <= cover; i++){
        cover = max(i + nums[i],cover);
        if(cover >= index) return true;
    }
    return false;
}
int main()
{
    vector<int> arr= {1,1,1,3,3,4,3,2,4,2};
    cout << canJump(arr);
    return 0;
}
