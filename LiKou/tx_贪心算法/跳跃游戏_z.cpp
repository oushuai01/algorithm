#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canJump(vector<int>& nums) {
    int cover = 0;
    int index = nums.size() - 1;
    if(index == 0)
    return true;
    for(int i = 0; i <= cover; ++i){
        cover = max(i + nums[i], cover);
        if(cover >= index) return true;
    }
    return false;
}
int main(){
    vector<int> num = {2,3,1,1,4};
    cout << canJump(num);
    return 0;
}