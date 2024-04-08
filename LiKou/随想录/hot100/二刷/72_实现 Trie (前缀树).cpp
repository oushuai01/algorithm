#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

// 2024-04-08
// 题解--前缀树
// https://leetcode.cn/problems/implement-trie-prefix-tree/solutions/98390/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt
class Trie {
public:
    Trie(){
        isEnd = 0;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        for(auto ch : word){
            if(node->next[ch - 'a'] == nullptr){
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto ch : word){
            if(node->next[ch - 'a'] == nullptr){
                return false;
            }
            node = node->next[ch - 'a'];
        }

        return node->isEnd;

    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto ch : prefix){
            if(node->next[ch - 'a'] == nullptr){
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return true;
    }
private:
    bool isEnd;
    Trie* next[26];
};
