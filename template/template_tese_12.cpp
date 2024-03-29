#include <iostream>
#include "string.h"
#include "template_tese_12.h"
using namespace std;

//构造函数 类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数 类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}
void test01()
{
	Person<string, int> p("Tom", 10);
	p.showPerson();
}


int main() {
    test01();
}