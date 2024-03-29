#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if(nums.size() == 1)
    return 1;
    if(nums.size() == 2){
        if(nums[0] != nums[1])
        return 2;
        else
        return 1;
    }
    int count = 1;
    int flag = 0;
    for(int i = 1; i < nums.size(); ++i){
        if(nums[i] - nums[i - 1] == 0) continue;
        if(nums[i] - nums[i - 1] > 0){
        if(flag != 0 && flag == 1) continue;
        flag = 1;
       }
       else{
        if(flag != 0 && flag == -1) continue;
        flag = -1;
       }
       count++;
    }
    return count;

        // int res=1;
        // int flag=0;
        // int first=0;
        // for (int i = 0; i < nums.size()-1; ++i) {
        //     if(nums[i]<nums[i+1]&&(flag==0||first==0)){
        //         res++;
        //         flag=1;
        //         first=1;
        //     } 
        //     if(nums[i]>nums[i+1]&&(flag==1||first==0)){
        //         res++;
        //         flag=0;
        //         first=1;
        //     }
        // }
        // return res;

}

int main(){
    vector<int> num = {33,12,35};
    cout << wiggleMaxLength(num);
    return 0;
}
