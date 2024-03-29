#include <iostream>
#include <vector>
using namespace std;

//双指针
int minSubArrayLen(int target, vector<int>& nums) {
    int result = INT32_MAX;
    int i = 0;
    int sum = 0;       //总和
    int subLength  = 0;  //长度
    for(int j = 0; j < nums.size(); j++){
        sum += nums[j];
        while(sum >= target){
            subLength  = j - i + 1;
            result = result > subLength  ? subLength : result;
            sum -= nums[i];
            i++;
        }
    }
    return result == INT32_MAX ? 0 : result;
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << minSubArrayLen(target,nums);
    return 0;
}