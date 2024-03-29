#include <iostream>
#include "string.h"
using namespace std;
//构造函数和析构函数
class Person{
    public:
        //构造函数
        Person(){
            cout << "Person的构造函数" << endl;
        }
        //有参构造函数
        Person(int a) {
            age = a;
            cout << "有参构造函数!" << endl;
	    }  
        Person(const Person& p) {
            age = p.age;
            cout << "拷贝构造函数!" << endl;
        }
        //析构函数
        // 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
        ~Person(){
            cout << "Person的析构函数调用" << endl;
        }

    private:
            int age;

};
void test01()
{
	Person p;
}
void test02(){
    //2.1  括号法，常用
	Person p1(10);

    //2.2 显式法
	Person p2 = Person(10); 
	Person p3 = Person(p2);
    //Person(10)单独写就是匿名对象  当前行结束之后，马上析构

    //2.3 隐式转换法
	Person p4 = 10; // Person p4 = Person(10); 
	Person p5 = p4; // Person p5 = Person(p4); 
    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明


	// Person p5(p4);    // Person p5 = Person(p4); 
}
Person doWork2()
{
	Person p1;
	cout << (int *)&p1 << endl;
	return p1;
}

int main(){
    test01();
    test02();
    doWork2();
   
    //system("pause");
}