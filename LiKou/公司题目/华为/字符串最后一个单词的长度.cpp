#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    getline(cin, str);   // 将一行输入字符串放到 str
    int count = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] == ' ') break;

        count++;
    }

    cout << count;
}
// 64 位输出请用 printf("%lld")