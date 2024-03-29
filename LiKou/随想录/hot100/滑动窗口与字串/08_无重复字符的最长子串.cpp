/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-12 11:12:11
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-14 20:43:42
 * @FilePath: \algorithm\LiKou\随想录\hot100\滑动窗口与字串\08_无重复字符的最长子串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.13
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <iostream>
using namespace std;


int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return 0;
    unordered_set<int> uset;
    int left = 0;
    int maxlen = INT_MIN;
    for(int i = 0; i < s.size(); i++){
        //从左到右寻找重复的元素  直到删除为止
        while(uset.find(s[i]) != uset.end()){
            uset.erase(s[left]);
            left++;
        }
        maxlen = maxlen > (i - left + 1) ? maxlen : (i - left + 1);
        uset.insert(s[i]);
    }

    return maxlen;
}


//也可以用滑动窗口的框架
int lengthOfLongestSubstring_(string s) {
    unordered_map<char, int> window;

    int left = 0, right = 0;
    int res = 0; // 记录结果
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        window[c]++;
        // 判断左侧窗口是否要收缩
        while (window[c] > 1) {
            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            window[d]--;
        }
        // 在这里更新答案
        res = max(res, right - left);
    }
    return res;
}
