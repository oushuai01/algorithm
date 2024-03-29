#include <iostream>
#include <vector>

using namespace std;
//10.26

vector<vector<int>> result; // 存放符合条件结果的集合
vector<int> path; // 用来存放符合条件结果
void backtracking(int n, int k, int startIndex){
    if(path.size() == k){              //终止条件
        result.push_back(path);        //存放结果
        return;
    }

    for(int i = startIndex; i <= n; i++){
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