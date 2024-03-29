// string插入和删除
//对string字符串进行插入和删除字符操作

// **函数原型：**
// string& insert(int pos, const char* s);                  //插入字符串
// string& insert(int pos, const string& str);         //插入字符串
// string& insert(int pos, int n, char c);                //在指定位置插入n个字符c
// string& erase(int pos, int n = npos);                    //删除从Pos开始的n个字符 

//字符串插入和删除
#include <string>
#include <iostream>
using namespace std;
void test01()
{
    string str = "hello";
    str.insert(0,"os");
    cout << str << endl;
    
    str.erase(2,1);  //从2号位置开始3个字符
	cout << str << endl;
}
int main() {

	test01();
}

//**总结：**插入和删除的起始下标都是从0开始