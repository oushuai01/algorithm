/* 9.27 */

#include <queue>
using namespace std;

/* 一个队列即可实现 */
class MyStack {
public:
    queue<int> que1;
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size_ = que1.size();
        int temp;
        while(--size_){
            //将弹出的元素 重新加入到队列
            temp = que1.front();
            que1.pop();
            que1.push(temp);
        }
        int res = que1.front();
        que1.pop();
        return res;

    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};