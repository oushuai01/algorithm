// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
// 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Person{
    public:
        Person(string name,int age,int hight){
            this->m_Name = name;
            this->m_Age =age;
            this->m_Hight = hight;
        }
    public:
        string m_Name;
        int m_Age;
        int m_Hight;
};
void printPerson(const list<Person> &person){
    for(list<Person>::const_iterator it = person.begin(); it != person.end(); it++){
        cout << (*it).m_Name << "  " << (*it).m_Age << "  " << (*it).m_Hight << endl;
    }
}
bool cmp(Person p1,Person p2){
    if(p1.m_Age == p2.m_Age){
        return p1.m_Hight > p2.m_Hight;
    }
    else{
        return p1.m_Age < p2.m_Age;
    }

}
void test01(){
    list<Person> L;

	Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

    L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

    cout << "排序前" << endl;
    printPerson(L);
    L.sort(cmp);
    cout << "排序后"<< endl;
    printPerson(L);

}
int main(){
    test01();
}

// 总结：
// * 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
// * 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
