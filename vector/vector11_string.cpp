//从字符串中获取想要的子串
// **函数原型：**
// string substr(int pos = 0, int n = npos) const;   //返回由pos开始的n个字符组成的字符串
#include <string>
#include <iostream>
using namespace std;
//子串
void test01()
{
    string str = "abcdefg";
    string str1 = str.substr(1,3);
    cout << "subStr = " << str1 << endl;

    string mail = "1768621963@qq.com";
    int pos = mail.find("@");
    string username = mail.substr(0,pos);  //返回由pos开始的 n个 字符组成的字符串
    cout << "username: " << username  << endl;

}

int main(){
    test01();
}

//灵活的运用求子串功能，可以在实际开发中获取有效的信息