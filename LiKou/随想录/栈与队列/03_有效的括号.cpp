/* 9.28 */
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    if(s.size() % 2 != 0) return false;
    stack<char> data;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') data.push(')');
        else if(s[i] == '{')  data.push('}');
        else if(s[i] == '[')  data.push(']');
        //匹配的括号一定是相邻的  如果出现第一次出现 右括号 那就是不匹配
        else if(data.empty() || data.top() != s[i]) return false;
        else data.pop();
    }

    return data.empty();
}

int main(){
    string ss = "()[]{}";
    cout << isValid(ss);
}