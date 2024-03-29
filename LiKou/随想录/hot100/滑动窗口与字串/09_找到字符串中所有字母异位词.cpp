#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
//10.14
//套模板
vector<int> findAnagrams(string s, string p) {
    vector<int> vec;
    unordered_map<char,int> need,window;
    int left = 0, right = 0;
    //条件
    int vaild = 0;
    for(char a : p)
    need[a]++;
    while(right < s.size()){
        char push = s[right];
        right++;

        if(need.count(push)){
            window[push]++;
            //拥有的 和 需要的 相等  达成一个条件
            if(window[push] == need[push])
            vaild++;
        }

        while(right - left >= p.size()){
            if(vaild == need.size()){
                vec.push_back(left);
            }
            char pop = s[left];
            left++;

            if(need.count(pop)){
                //拥有的 和 需要的 相等  达成一个条件
                if(window[pop] == need[pop])
                vaild--;
                window[pop]--;
            }
        }

    }
    return vec;
}
