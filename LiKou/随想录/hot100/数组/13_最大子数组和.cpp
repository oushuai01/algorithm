/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-16 20:11:49
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-16 20:29:19
 * @FilePath: \algorithm\LiKou\随想录\hot100\数组\13_最大子数组和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
using namespace std;
//贪心
int maxSubArray(vector<int>& nums) {
    int max_num = INT_MIN;
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        count += nums[i];
        if(count > max_num)
        max_num = count;

        if(count <= 0)
        count = 0;
    }

    return max_num;
}