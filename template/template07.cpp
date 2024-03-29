#include <iostream>
#include "string.h"
using namespace std;


template<class NameType,class AgeType>
class Person{

public:
Person(NameType name,AgeType age){
    this->name = name;
    this->age = age;
}
void showPerson(){
    cout << "name = " << name << "   " <<"age = " << age << endl;
}

public:
NameType name;
AgeType age;

};

void test01(){
    Person<string,int>p1("孙悟空",19);
    p1.showPerson();
}
int main(){
    test01();

}
//总结：类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板
//类模板与函数模板区别
// 类模板与函数模板区别主要有两点：
// 1. 类模板没有自动类型推导的使用方式
// 2. 类模板在模板参数列表中可以有默认参数  template<class NameType,class AgeType = int>
