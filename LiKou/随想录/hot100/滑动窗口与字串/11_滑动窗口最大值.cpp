#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <iostream>
#include <unordered_map>
using namespace std; 

//10.16
//单调队列
class Myqueue{
    public:
        void pop(int value){
            if(!que.empty() && value == que.front())
            que.pop_front();
        }

        void push(int value){
            while(!que.empty() && que.back() < value){
                //相同的数字会加入到队列
                que.pop_back();
            }
            que.push_back(value);
        }

        int front(){
            return que.front();
        }
    
    public:
    deque<int> que;
    
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    Myqueue que;
    vector<int> result;
    for(int i = 0; i < k; i++){
        que.push(nums[i]);
    }
    result.push_back(que.front());

    for(int i = k; i < nums.size(); i++){
        que.pop(nums[i - k]);
        que.push(nums[i]);
        result.push_back(que.front());
    }

    return result;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for(int num : result)
    cout << num << " ";
}