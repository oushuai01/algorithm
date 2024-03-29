#include <iostream>
#include <stack>
using namespace std;

// 2024-03-28
bool isValid(string s) {
    if(s.size() % 2 != 0) return false;
    stack<char> data;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') data.push(')');
        else if(s[i] == '{') data.push('}');
        else if(s[i] == '[') data.push(']');
        // 如果栈为空 或者 右括号不匹配
        else if(data.empty() || s[i] != data.top()) return false;
        else data.pop();
    }

    return data.empty();
}