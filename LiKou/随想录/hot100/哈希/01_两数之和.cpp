/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-10 10:44:34
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-10 11:14:16
 * @FilePath: \algorithm\LiKou\随想录\hot100\哈希\01_两数之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//10.10
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int,int> umap;
    for(int i = 0; i < nums.size(); i++){
        umap[nums[i]] = (i + 1);
    }
    for(int i = 0; i < nums.size(); i++){
        if(umap[target - nums[i]] != 0 && (umap[target - nums[i]] != (i + 1))){
            //cout << i << " ";
            res.push_back(i);
            res.push_back(umap[target - nums[i]] - 1);
            return res;
        }
    }
    return res;
}


//标准
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};


int main(){
    vector<int> res;
    vector<int> num = {1, 3, 5 , 9 , 8};
    int target = 14;
    res = twoSum(num, target);
    for(int re : res)
    cout << re << " ";
}