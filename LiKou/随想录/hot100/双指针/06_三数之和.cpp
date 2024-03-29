/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-12 10:40:48
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-12 11:12:18
 * @FilePath: \algorithm\LiKou\随想录\hot100\双指针\06_三数之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-12 10:40:48
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-12 11:11:57
 * @FilePath: \algorithm\LiKou\随想录\hot100\双指针\06_三数之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//10.12
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){

        //如果第一个数字都大于0 那么后面不可能有相加等于0
        if(nums[i] > 0) return res;


        //去掉第一个重复的元素
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = nums.size() - 1;

        while(left < right){
            if((nums[i] + nums[left] + nums[right]) < 0) left++;
            else if((nums[i] + nums[left] + nums[right]) > 0) right--;
            else{
                res.push_back({nums[i], nums[left], nums[right]});

                 //去掉后两个重复的元素
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
        }

    }

    return res;
}



