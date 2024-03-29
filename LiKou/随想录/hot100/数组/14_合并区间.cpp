/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-17 10:26:49
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-17 10:54:55
 * @FilePath: \algorithm\LiKou\随想录\hot100\数组\14_合并区间.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int>&a, vector<int>&b){
    if(a[0] == b[0])
    return a[1] < b[1];
    else
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> result;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for(vector<int> nums : intervals){
        if(nums[0] <= end){
            //更新end   要用max
            end = max(nums[1], end);
        }
        else if(nums[0] > end){
            //更新result   并且更新start end
            result.push_back({start, end});
            start = nums[0];
            end = nums[1];
        }
    }
    //push最后一个start end
    result.push_back({start, end});
    
    return result;
}

int main(){
    vector<vector<int>> vec = {{1,3},{1,2},{8,10},{15,18}};
    vector<vector<int>> res = merge(vec);
    for(vector<int> nums : res){
        for(int num: nums)
        cout << num << " ";
        cout << "|";
    }
}