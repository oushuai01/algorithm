#include <unordered_set>
#include <unordered_map>
using namespace std;



int lengthOfLongestSubstring(string s){
    if(s.size() == 0) return 0;
    unordered_set<char> uset;
    int left = 0;
    int maxlen = 0;

    for(int i = 0; i < s.size(); i++){
        while(uset.find(s[i]) != uset.end()){
            uset.erase(s[left]);
            left++;
        }

        maxlen = maxlen > (i - left + 1) ? maxlen : (i - left + 1);
        uset.insert(s[i]);
    }

    return maxlen;
}


// 滑动窗口
int lengthOfLongestSubstring_(string s){
    unordered_map<char,int> need, windows;
    int left = 0, right = 0;
    int valid = 0;


    while(right < s.size()){
        char c = s[right];
        right++;
        windows[c]++;

        while(windows[c] > 1){
            char d = s[left];
            left++;
            windows[d]--;
        }

        valid = max(valid, right - left + 1);
    }

    return valid;
}