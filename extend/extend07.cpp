#include <iostream>
#include "string.h"
using namespace std;

class Animal
{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 150;

	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;   //150
	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;      //150
	cout << "st.m_Age = " << st.m_Age << endl;                 //150
}


int main() {

	test01();

	//system("pause");

	return 0;
}

//菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
//利用虚继承可以解决菱形继承问题