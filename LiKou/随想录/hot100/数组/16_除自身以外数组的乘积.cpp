#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//双向遍历
//题解
//https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/solutions/208840/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> vec(nums.size(), 1);
    int temp = 1;
    //前->后
    for(int i = 1; i < nums.size(); i++){
        vec[i] = vec[i - 1] * nums[i - 1];
    }

    //后->前
    for(int i = nums.size() - 2; i >= 0; i--){
        temp *= nums[i + 1];
        vec[i] *= temp;
    }

    return vec;
}

int main(){
    vector<int> vec = {1,2,3,4,5,1};
    vector<int> res = productExceptSelf(vec);
    for(int num : res)
    cout << num << " ";
}




//类似题目
//191. 按规则计算统计结果
//https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/description/
vector<int> statisticalResult(vector<int>& arrayA) {
    vector<int> result(arrayA.size(), 1);
    int temp = 1;
    //前->后
    for(int i = 1; i < arrayA.size(); i++)
    result[i] = result[i - 1] * arrayA[i - 1];

    //后->前
    for(int i = arrayA.size() - 2; i >= 0; i--){
        temp *= arrayA[i + 1];
        result[i] *= temp;
    }

    return result;

}