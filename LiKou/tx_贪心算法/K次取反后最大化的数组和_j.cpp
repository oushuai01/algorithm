#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a, int &b){
    return abs(a) > abs(b);
}
int largestSumAfterKNegations(vector<int>& nums, int k) {
    // int res = 0;
    // int size_ = nums.size();
    // sort(nums.begin(),nums.end());
    // for(int i = 1; i <= k; i++){
    //     if(i < size_){
    //         if(nums[i - 1] < 0) nums[i - 1] *= -1;
    //         else if(nums[i - 1] == 0){
    //             break;
    //         }
    //         else if(nums[i - 1] > 0){
    //             if(nums[i - 1] > nums[i]){
    //                 if((k - i -1) % 2 == 0)
    //                 nums[i] *= 1;
    //                 else
    //                 nums[i] *= -1;
    //                 break;
    //             }
    //             else{
    //                 if((k - i - 1) % 2 == 0)
    //                 nums[i - 1] *= 1;
    //                 else
    //                 nums[i - 1] *= -1;
    //                 break;
    //             }
    //         }
    //     }
    //     else{
    //         sort(nums.begin(),nums.end());
    //         if((k - i - 1) % 2 == 0)
    //         nums[0] *= 1;
    //         else
    //         nums[0] *= -1;
    //         break;
    //     }
    // }
    // for(int i = 0; i < nums.size(); i++){
    //     res += nums[i];
    // }
    

    // return res;
    int res = 0;
    sort(nums.begin(),nums.end(),cmp);
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] < 0 && k > 0){
            nums[i] *= -1;
            k--;
        }
    }
    if(k % 2 == 1) nums[nums.size() - 1] *= -1;
    for(int i = 0; i < nums.size(); i++){
        res += nums[i];
    }

    return res;

}
int main(){
    vector<int> num = {4,2,3};
    int k = 1;
    cout << largestSumAfterKNegations(num,k);
    return 0;
}