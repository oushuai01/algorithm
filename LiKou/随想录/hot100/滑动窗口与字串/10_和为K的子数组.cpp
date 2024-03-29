/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-15 16:28:41
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-15 17:07:12
 * @FilePath: \algorithm\LiKou\随想录\hot100\滑动窗口与字串\10_和为K的子数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std; 
//10.15

//和为 K 的子数组
//https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> umap;
    umap[0] = 1;
    int preSum = 0;
    int ans = 0;
    for(int num: nums){
        preSum += num;
        if(umap.count(preSum - k)){
            //表示前面有多少个区间满足条件
            ans += umap[preSum - k];
        }
        //前缀和区间++
        umap[preSum]++;
    }

    return ans;
}

//例如  下面数据为前缀和
// 1 3 5 9 4 5 6 9           k = 4

//区间
//那么 1  5是一个
//     5   9是一个
//     1    5 是一个
//     5    9 此时有两个
//一共的连续空间就是  1 + 1 + 1 + 2 = 5