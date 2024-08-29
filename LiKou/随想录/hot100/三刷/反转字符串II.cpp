#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseStr(string s, int k) {
    for(int i = 0; i < s.size(); i += (2 * k)){
        // 1. 每隔 2k 个字符的前 k 个字符进行反转
        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
        if(i + k <= s.size()){
            reverse(s.begin() + i, s.begin() + k + i);
            continue;
        }

        // 如果剩余的小于k
        reverse(s.begin() + i, s.begin() + s.size());
    }

    return s;
 }