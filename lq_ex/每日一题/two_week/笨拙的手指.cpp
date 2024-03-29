#include <iostream>
#include <map>
#include <math.h>
using namespace std;

// 利用map 得知哪个数字出现了两次

//二进制转十进制
long long two_(string ss){
    int size_ss = ss.size();
    long long sum = 0;
    for(int i = 0; i < ss.size(); ++i) sum += ((ss[i] - '0') * pow(2, ss.size() - 1 -i));
    return sum;
}
//三进制转十进制
long long three_(string ss){
    int size_ss = ss.size();
    long long sum = 0;
    for(int i = 0; i < ss.size(); ++i) sum += ((ss[i] - '0') * pow(3, ss.size() - 1 - i));
    return sum;
}
int main(){
    string s_two;
    string s_three;
    cin >> s_two >> s_three;
    map<long long,int> map_num;
    
    // 两个长度为 1    只能两个都是 0
    if(s_two.size() == 1 && s_three.size() == 1)
    {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < s_two.size(); ++i){
        string ss_temp = s_two;
        ss_temp[i] == '0' ? ss_temp[i] = '1':ss_temp[i] = '0';

        // 特判最高位不能为 0
        if(i == 0)
        ss_temp[i] = '1';

        map_num[two_(ss_temp)]++;
    }


    for(int i = 0; i < s_three.size(); ++i){
        string ss_temp = s_three;
        for(int j = 1; j <= 2; j++){
            // 特判最高位不能为 0 
            if(i == 0 && ss_temp[i] != '0'){
                ss_temp[i] == '1'? ss_temp[i] = '2' : ss_temp[i] = '1';
                j = 2;
            }
            else{
                ss_temp[i]++;
                if(ss_temp[i] - '2' >= 1){
                ss_temp[i] = '0';
                }
            }
            map_num[three_(ss_temp)]++;
            if(map_num[three_(ss_temp)] > 1){
                cout << three_(ss_temp);
                return 0;
            }
        }
    }
    return 0;
}