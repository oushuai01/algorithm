
#include <iostream>
#include <string.h>
using namespace std;
template <class T>
class Base{
    T m;
};
//class Son:public Base  //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son: public Base<int>{//必须指定一个类型

};

void tese01(){
    Son s;
}

template <class T1,class T2>
class Son2: public Base<T2>{
    public:
        Son2(){
            cout << typeid(T1).name() << endl;
            cout << typeid(T2).name() << endl;
        }

};
void tese02(){
    Son2<int,char> child;
}

int main()
{
    tese01();

	tese02();
    return 0;
}
// 当类模板碰到继承时，需要注意一下几点：

// * 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// * 如果不指定，编译器无法给子类分配内存
// * 如果想灵活指定出父类中T的类型，子类也需变为类模板

//总结：如果父类是类模板，子类需要指定出父类中T的数据类型