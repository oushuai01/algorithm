/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-31 16:07:26
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-31 19:42:16
 * @FilePath: \algorithm\LiKou\随想录\回溯\08_复原IP地址.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//10.31
bool isVaild(string& s, int start, int end){
    if(start > end){
        return false;
    }
    if(end - start > 2)
    return false;

    //不能有前置0
    if(s[start] == '0' && start != end) return false;

    int num = 0;
    for(int i = start; i <= end; i++){
        //字符错误
        if(s[i] < '0' || s[i] > '9')
        return false;

        num = num * 10 + s[i] - '0';
        
        //数值超过255
        if(num > 255)
        return false;

    }

    return true;
}
vector<string> result;
void backtrack(string& s, int start, int pointNum){
    if(pointNum == 3){
        //判断第四段是否合法
        if(isVaild(s, start, s.size() - 1)){
            result.push_back(s);
        }
        return;
    }

    for(int i = start; i < s.size(); i++){
        if(isVaild(s, start, i)){
            //插入一个点
            s.insert(s.begin() + i + 1, 1, '.');
            backtrack(s, i + 2, pointNum + 1);
            s.erase(s.begin() + i + 1);
        }
        else break;
    }
}

vector<string> restoreIpAddresses(string s) {
    if(s.size() == 0) return result;

    backtrack(s, 0, 0);

    return result;
}