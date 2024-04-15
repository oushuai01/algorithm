#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;

// 2024-04-15

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    // dp表示 字符串长度为i的话，dp[i]为true，表示可以拆分为一个或多个在字典中出现的单词。
    dp[0] = true;

    for(int i = 1; i <= s.size(); i++){ // 先遍历背包
        for(int j = 0; j < i; j++){     // 再遍历物品
            string word = s.substr(j, i - j);  //substr(起始位置，截取的个数)
            // 如果能找到  且dp[j]也为true 说明能被拆分为dp[j] 和  word
            if(words.find(word) != words.end() && dp[j])
            dp[i] = true;
        }
    }

    return dp[s.size()];
} 