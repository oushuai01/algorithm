#include <iostream>
#include <stack>
using namespace std;

// 2024-04-04

class MinStack {
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        sta.push(val);
        // 栈顶存入小的值
        min_stack.push(min(min_stack.top(), val));
    }
    
    void pop() {
        sta.pop();
        min_stack.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> sta;
    stack<int> min_stack;
};