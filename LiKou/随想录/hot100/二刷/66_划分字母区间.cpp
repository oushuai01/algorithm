#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2024-04-07

vector<int> partitionLabels(string s) {
    // 统计每个字母最大下标
    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a'] = i;
    }

    vector<int> result;
    int left = 0;
    int right = 0;
    for(int i = 0; i < s.size(); i++){
        right = max(right, hash[s[i] - 'a']);  // 找到字符出现的最远边界
        if(i == right){
            result.push_back(right - left + 1);
            left = i + 1;
        }
    }

    return result;
}