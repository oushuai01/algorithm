#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        // 第一个元素都大于0，后面相加也都会大于0
        if(nums[i] > 0) return res;


        // 去除第一个重复元素
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = nums.size() - 1;

        while(left < right){
            if((nums[i] + nums[left] + nums[right]) > 0) right--;
            else if((nums[i] + nums[left] + nums[right]) < 0) left++;
            else{
                res.push_back({nums[i], nums[left], nums[right]});
                // 去除后两个重复元素
                while(left < right && nums[right] == nums[right - 1]) right--;
                while(left < right && nums[left] == nums[left + 1]) left--;

                left++;
                right--;
            }
        }
    }

    return res;
}