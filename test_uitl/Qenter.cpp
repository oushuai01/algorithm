#include <string>
#include <iostream>
using namespace std;
// 去除英文的回车
// 不能读中文    使用 | 结尾
void test01(){
    string str ;
    getline(cin,str,'|');
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '\n'){
            str.erase(i,1);
            i = i - 1;
        }
    }
    cout << "结果：" << str;
}
int main(){
    while(1)
    test01();
}