#include <iostream>
#include "string.h"
using namespace std;
//继承中构造和析构顺序
class Base 
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}
	~Base()
	{
		cout << "Base析构函数!" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son构造函数!" << endl;
	}
	~Son()
	{
		cout << "Son析构函数!" << endl;
	}

};


void test01()
{
	//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
	Son s;
}

int main() {

	test01();

	//system("pause");

	return 0;
}

// >总结：继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反

