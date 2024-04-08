#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2024-04-06

class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(A.size() != B.size()){
            A.push(num);
            B.push(A.top());
            A.pop();
        }else{
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }
    
    double findMedian() {
        return A.size() == B.size() ? double((A.top() + B.top()) / 2.0) : A.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> A;  // 小顶堆  用来存储较大元素的一边
    priority_queue<int, vector<int>, less<int>> B; // 大顶堆  用来存储较小元素的一边 
    // 他们两个的头部就是中位数
};

