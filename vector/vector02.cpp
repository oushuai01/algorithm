//学习目标：vector中存放自定义数据类型，并打印输出

#include <vector>
#include <string>
#include <iostream>
using namespace std;
//自定义数据类型
class Person{
    public:
        Person(string name,int age){
            this->mName = name;
            this->mAge = age;

        }
    public:
       string mName;
	   int mAge;
};
//存放对象
void test01(){
    vector<Person> v;

    Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name= " << it->mName << "   Age= " << it->mAge << endl;
        //or
        // cout << "Name= " << (*it).mName << "Age= " << (*it).mAge << endl;
    }
    cout << "---" << endl;
}

//存放对象指针
void test02(){
    vector<Person*> v;
    
    Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

    v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        Person *p = *it;

        cout << "Name= " << p->mName << "   Age= " << p->mAge << endl;
        //or
        // cout << "Name= " << (*p).mName << "Age= " << (*p).mAge << endl;
    }

}


int main() {

	test01();
    
	test02();
}