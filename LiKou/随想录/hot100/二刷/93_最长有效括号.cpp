#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;

// 2024-04-16

// 栈的实现方法
// https://leetcode.cn/problems/longest-valid-parentheses/solutions/314827/shou-hua-tu-jie-zhan-de-xiang-xi-si-lu-by-hyj8
int longestValidParentheses(string s) {
    stack<int> sta;
    int maxLen = 0;
    // 添加 -1 为了防止判空
    sta.push(-1);

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
        sta.push(i);
        else{
            sta.pop();
            if(!sta.empty()){
                int len = i - sta.top();
                maxLen = max(len, maxLen);
            }else{
                // -1 出栈用 ) 替代
                sta.push(i);
            }
        }
    }

    return maxLen;
}