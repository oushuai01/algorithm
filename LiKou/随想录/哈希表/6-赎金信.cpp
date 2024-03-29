#include <iostream>
#include <unordered_map>
using namespace std;
// 或者用数组也行
bool canConstruct(string ransomNote, string magazine) {
    if(magazine.size() < ransomNote.size())
    return false;

    unordered_map<char,int> umap;
    for(char imag : magazine){
        umap[imag]++;
    }
    for(char ran : ransomNote){
        umap[ran]--;
        if(umap[ran] < 0)
        return false;
    }
    return true;


}
int main(){




}