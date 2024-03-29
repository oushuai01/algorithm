#include <iostream>
#include <vector>
//10.26
using namespace std;


vector<vector<int>> result; // 存放符合条件结果的集合
vector<int> path; // 用来存放符合条件结果
void backtracking(int n, int k, int startIndex){
    if(path.size() == k){              //终止条件
        result.push_back(path);        //存放结果
        return;
    }
    //剪枝
    //n - i >= k - path.size()   为什么要加 1  举个例子就行
    for(int i = startIndex; i <= n - k + path.size() + 1; i++){   //优化的地方
        path.push_back(i);            //处理节点;
        backtracking(n, k, i + 1);    // 递归
        path.pop_back();              //回溯，撤销处理结果
    }

}

vector<vector<int>> combine(int n, int k) {
    result.clear();
    path.clear();
    backtracking(n, k, 1);

    return result;
}