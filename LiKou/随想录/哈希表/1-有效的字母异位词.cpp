#include <iostream>
#include <string>

using namespace std;
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int arr[26] = {0};
    for(int i = 0; i < s.size(); i++){
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(arr[i] != 0)
        return false;
    }
    return true;

}
int main(){
    string ss = "qwerfdsa";
    string tt = "qsdfrewa";
    cout << isAnagram(ss,tt);

    return 0;
}