/* 9.28 */
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(!st.empty() && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }
    string res = "";
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}



//当然可以拿字符串直接作为栈，这样省去了栈还要转为字符串的操作。
string removeDuplicates(string S) {
    string result;
    for(char s : S) {
        if(result.empty() || result.back() != s){
            result.push_back(s);
        }
        else {
            result.pop_back();
        }
    }
    return result;
}