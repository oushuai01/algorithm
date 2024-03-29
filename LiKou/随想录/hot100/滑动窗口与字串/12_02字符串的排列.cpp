/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-14 20:19:46
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-14 20:37:55
 * @FilePath: \algorithm\LiKou\随想录\hot100\滑动窗口与字串\12_02字符串的排列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std; 
//10.14
//567. 字符串的排列
//力扣链接： https://leetcode.cn/problems/permutation-in-string/
bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    unordered_map<char,int> need, windows;
    
    for(char s: s1) need[s]++;

    int left = 0, right = 0;
    int vaild = 0;
    while(right < s2.size()){
        char push = s2[right];
        right++;

        if(need.count(push)){
            windows[push]++;
            if(need[push] == windows[push])
            vaild++;
        }
        //debug
        // cout << "---------" << endl;
        // cout << vaild << endl;
        
        while(right - left >= s1.size()){
            if(vaild == need.size()) return true;

            char pop = s2[left];
            left++;
            if(need.count(pop)){
                if(windows[pop] == need[pop])
                vaild--;
                windows[pop]--;
            }
        }

    }

    return false;
}


int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool flag = checkInclusion(s1, s2);
    cout << flag;
}