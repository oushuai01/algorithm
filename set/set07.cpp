//set存放自定义数据类型

#include <set>
#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;

};

class MyCompare{
    public:
        bool  operator()(const Person &p1,const Person &p2){
            return p1.m_Age > p2.m_Age;
        }

};

void test01()
{
	set<Person, MyCompare> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
    for (set<Person, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}
int main() {

	test01();
}
// 总结：
// 对于自定义数据类型，set必须指定排序规则才可以插入数据