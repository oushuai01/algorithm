#include <iostream>
#include <stack>
using namespace std;

// 2024-04-04

stack<char> sta;
bool isValid(string s) {
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[') sta.push(']');
        else if(s[i] == '{') sta.push('}');
        else if(s[i] == '(') sta.push(')');
        else if(s[i] != sta.top()) return false;
        else sta.pop();
    }

    return sta.empty();
}