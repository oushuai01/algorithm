#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 2024-04-01
vector<string> path;
vector<vector<string>> result;
// 检测是否是回文字符串
bool cheack(string str){
    if(str.size() == 0) return false;
    else if(str.size() == 1) return true;
    for(int i = 0, j = str.size() - 1; i < str.size() / 2; i++, j--){
        if(str[i] != str[j]) return false;
    }

    return true;
}

void backTrack(string s, int start){
    if(start >= s.size()) {
        result.push_back(path);
        return;
    }
    for(int i = start; i < s.size(); i++){
        if(cheack(s.substr(start, i - start + 1))){ // 检测是否是回文字符串
        // substr 是获取 start 开始后面几个元素的
        // substr(std::size_t __pos, std::size_t __n)
            path.push_back(s.substr(start, i - start + 1));
        }else  // 不是则跳过
        continue;
        backTrack(s, i + 1);
        path.pop_back();

    }
    
}

vector<vector<string>> partition(string s) {
    backTrack(s, 0);
    return result;
}