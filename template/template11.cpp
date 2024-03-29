//学习目标：能够掌握类模板中的成员函数类外实现

#include <iostream>
#include <string.h>
using namespace std;
//类模板中成员函数类外实现
template <class T1,class T2>
class Person{
    public:
        //成员函数类内声明
        Person(T1 name,T2 age);
        void showPerson();
    public:
        T1 m_name;
        T2 m_age;
};

//类外实现
class A{
    public:
        void tese();
};

void A::tese(){
    cout << "os" << endl;
}

//构造函数 类外实现
template <class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    this->m_name = name;
    this->m_age = age;
}

//成员函数 类外实现
template <class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout << "xm = " << this->m_name << "  age = " << this->m_age << endl;
}

void tese(){
    Person<string,int> p("Tom",20);
    p.showPerson();
    A a;
    a.tese();
}

int main(){
    tese();
}

//总结：类模板中成员函数类外实现时，需要加上模板参数列表