/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-14 19:55:28
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-15 17:08:01
 * @FilePath: \algorithm\LiKou\随想录\hot100\滑动窗口与字串\12_最小覆盖字串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;  
   
//10.14
//套模板
string minWindow(string s, string t) {
    string result = "";
    if(s.size() < t.size())
    return result;
    unordered_map<char,int> windows, need;
    for(char s : t) need[s]++;

    int left = 0, right = 0;
    int vaild = 0;
    int len = INT_MAX;
    int start = 0;
    while(right < s.size()){
        char push = s[right];
        right++;
        if(need.count(push)){
            windows[push]++;
            if(windows[push] == need[push])
            vaild++;
        }

        while(vaild == need.size()){
            if(right - left < len){
                len = right - left;
                start = left;
            }

            char pop = s[left];
            left++;

            if(need.count(pop)){
                if(windows[pop] == need[pop])
                vaild--;
                windows[pop]--;
            }

        }
    }
    result = len == INT_MAX ? "" : s.substr(start, len);
    return result;
}