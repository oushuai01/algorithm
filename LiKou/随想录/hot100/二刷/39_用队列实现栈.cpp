#include <queue>
using namespace std;




class MyStack {
public:
    // 一个队列就可以实现
    queue<int> que;
    MyStack() {

    }
    void push(int x) {
        que.push(x);
        // 每次push 都将进来的换到第一个位置
        int size_  = que.size();
        size_--;

        while(size_--){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int res = que.front();
        que.pop();
        return res;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }   
};


