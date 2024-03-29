#include <iostream>
#include "string.h"
using namespace std;

// 类模板中成员函数和普通类中成员函数创建时机是有区别的：

// * 普通类中的成员函数一开始就可以创建
// * 类模板中的成员函数在调用时才创建

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;

	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成

	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }

};

void test01()
{
	MyClass<Person1> m;
    MyClass<Person2> m2;
	
	m.fun1();
    m2.fun2();

	//m.fun2();//编译会出错，说明函数调用才会去创建成员函数
}

int main() {

	test01();

	//system("pause");

	return 0;
}
//总结：类模板中的成员函数并不是一开始就创建的，在调用时才去创建