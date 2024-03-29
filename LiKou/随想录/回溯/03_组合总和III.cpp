/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-26 09:53:25
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-26 10:00:12
 * @FilePath: \algorithm\LiKou\随想录\回溯\03_组合总和III.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
//10.26
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(int k, int n, int start, int sum){
    if(path.size() == k){
        if(sum == n){
            result.push_back(path);
            return;
        }
        return;
    }


    for(int i = start; i <= 9; i++){
        path.push_back(i);
        backtracking(k, n, i + 1, sum + i);
        path.pop_back();
    }
}


vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 1, 0);
    return result;
}

int main(){
    int n = 7;
    int k = 3;

    vector<vector<int>> res = combinationSum3(k, n);
    for(vector<int> path : res){
        for(int num : path)
        cout << num << " ";
        cout << "|";
    }

}