#include <iostream>
#include <stack>
using namespace std;

// 2024-03-28
class MyQueue {
public:
    stack<int> STin;
    stack<int> STout;

    MyQueue() {

    }
    
    void push(int x) {
        STin.push(x);
    }
    
    int pop() {
        int res = peek();
        STout.pop();
        return res;
    }
    
    int peek() {
        int res = 0;
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if(STout.empty()){
             while(!STin.empty()){
                 // 从stIn导入数据直到stIn为空
                int temp = STin.top();
                STin.pop();
                STout.push(temp);
            }
        }
        res = STout.top();
        return res;
    }
    
    bool empty() {
        if(STin.size() == 0 && STout.size() == 0) return true;
        else return false;
    }
};