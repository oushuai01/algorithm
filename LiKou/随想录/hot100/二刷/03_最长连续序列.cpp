/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-05 14:28:43
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-05 15:06:43
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\03_最长连续序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE#
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// 找到第一个元素  再往后查询
int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> umap;
    for(int i : nums){
        umap[i]++;
    }
    int res = 0;
    for(int i : nums){
        // 不是起点直接跳过
        if(umap[i-1]) continue;

        int len = 1;
        while(umap[++i]) len++;

        res = max(res, len);
    }

    return res;
}


// 使用列表
int longestConsecutive_(vector<int>& nums) {
    unordered_set<int> uset;
    for(int i : nums) uset.insert(i);
    int res = 0;
    for(int x : nums){
        // 找到开头的元素
        if(!uset.count(x - 1)){
            int y = x;

            while(uset.count(y)) y++;
            res = max(res, y - x);
        }
    }

    return res;
}