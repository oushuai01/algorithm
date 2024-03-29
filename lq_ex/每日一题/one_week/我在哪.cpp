#include <iostream>
#include <map>
using namespace std;

map<string,int> map_location;

int N;
string str;

bool cheak(int num){
    for(int i = 0; i < str.size(); ++i){
        // substr 返回    下标 i 后 长度为num的字符串
        string ss = str.substr(i,num);
        map_location[ss]++;
        if(map_location[ss] > 1){
            map_location.clear();
            return false;
        }
    }
    return true;
}
int main(){
    cin >> N;
    cin >> str;
    for(int i = 1; i <= str.size(); ++i){
        // 检查个数  就是查找 最小 不重复序列
       if(cheak(i)){
         cout << i;
         break;
       } 
    }
    
    return 0;
}
