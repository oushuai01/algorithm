#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    string str = "longlonglongistoolong";
    // cin >> str;
    map<char,int> map_;
    map_.insert(pair<char,int>(str[0],1));
    for(int i = 1; i < str.length(); ++i){
        map_[str[i]]++;
    }
    int max_val = map_.begin()->second;
    map<char,int>::iterator max_it = map_.begin();
    for(map<char,int>::iterator it = map_.begin(); it != map_.end(); ++it){
        if(it->second > max_val){
            max_val = it->second;
            max_it = it;
        }
    }
    cout << max_it->first << max_it->second;
}
