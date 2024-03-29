#include <vector>
#include <iostream>
using namespace std;

vector<int> partitionLabels(string s) {
    int hash[26];
    for(int i = 0; i < s.size(); ++i){
        hash[s[i] - 'a'] = i;
    }
    int left = 0;
    int right = 0;
    vector<int> res;
    for(int i = 0; i < s.size(); ++i){
        right = max(right, hash[s[i] - 'a']);
        if(i == right){
            res.push_back(right - left + 1);
            left = i + 1;
        }
    }

    return res;

}

int main(){
    string s = "ababcbacadefegdehijhklij";
    vector<int> vec = partitionLabels(s);
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i];
    }

}