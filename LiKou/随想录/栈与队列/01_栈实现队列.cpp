/* 9.27 */
#include <stack>
#include <iostream>
using namespace std;



class MyQueue {
public:
    stack<int> stIN;
    stack<int> stOUT;

    MyQueue() {

    }
    
    void push(int x) {
        stIN.push(x);
    }
    
    int pop() {
        int result;
        if(stOUT.empty()){
            int res;
            while(!stIN.empty()){
                res = stIN.top();
                stIN.pop();
                stOUT.push(res);
            }
        }

        result = stOUT.top();
        stOUT.pop();
        return result;
    }
    
    int peek() {
        int res;
        res = this->pop();
        stOUT.push(res);
        return res
    }
    
    bool empty() {
        if(stOUT.size() == 0 && stIN.size() == 0)
        return true;
        else
        return false;
    }
};