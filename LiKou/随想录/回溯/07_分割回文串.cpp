/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-07-04 21:07:23
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-30 16:25:23
 * @FilePath: \algorithm\LiKou\debug\debug.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//10.30
vector<vector<string>> result;
vector<string> path;

//判断是否为回文子串
bool isPalindrom(string& s, int start, int end){
    for(int i = start, j = end; i < j; i++, j--){
        if(s[i] != s[j])
        return false;
    }
    return true;
}

void backtrack(string& s, int start){
    // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
    if(start >= s.size()){
        result.push_back(path);
        return;
    }

    for(int i = start; i < s.size(); i++){
        if(isPalindrom(s, start, i)){   //是回文子串
            //获取在[start, i]在s中的字串
            path.push_back(s.substr(start, i - start + 1));
        }else{                 //不是则跳过
            continue;
        }

        backtrack(s, i + 1);
        path.pop_back();
    }
}
vector<vector<string>> partition(string s) {
    if(s.size() == 0) return result;
    backtrack(s, 0);
    return result;
}

