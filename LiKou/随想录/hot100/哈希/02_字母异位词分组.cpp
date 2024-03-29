/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-10 11:18:38
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-10 11:28:39
 * @FilePath: \algorithm\LiKou\随想录\hot100\哈希\02_字母异位词分组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//10.10
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> umaps;
    for(string str : strs){
        string data = str;
        //排序str 使得字母都是从小到大
        sort(str.begin(), str.end());
        umaps[str].push_back(data);
    }
    for(auto umap : umaps){
        res.push_back(umap.second);
    }
    return res;
}