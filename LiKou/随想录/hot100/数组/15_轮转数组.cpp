/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-17 11:07:47
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-19 10:26:28
 * @FilePath: \algorithm\LiKou\随想录\hot100\数组\15_轮转数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

//双向队列
void rotate(vector<int>& nums, int k) {
    deque<int> dque;
    for(int num : nums)
    dque.push_back(num);

    for(int i = 0; i < k; i++){
        int temp = dque.back();
        dque.pop_back();
        dque.push_front(temp);
    }

    for(int i = 0; i < nums.size(); i++){
        int temp = dque.front();
        dque.pop_front();
        nums[i] = temp;
    }
}



//第二种做法：用数组截断操作
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()){
            k %= nums.size();
        }
        vector<int> temp(nums.end() - k,nums.end());
        nums.erase(nums.end() - k,nums.end());
        nums.insert(nums.begin(),temp.begin(),temp.end());
    }
};
