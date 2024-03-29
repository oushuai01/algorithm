#include <iostream>
#include "string.h"
using namespace std;



//模板就是建立**通用的模具**，大大**提高复用性**
//语法
// template<typename T>
// 函数声明或定义

template<typename T>      //typename 可以用 class代替
void mySwap(T&a , T&b){
    T temp = a;
    a = b;
    b = temp;
}

void test01(){
    int a = 10;
    int b = 20;

    //利用模板实现交换
	//1、自动类型推导
	mySwap(a, b);

	//2、显示指定类型
	mySwap<int>(a, b);

    cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}
int main(){
    test01();

}
// * 函数模板利用关键字 template
// * 使用函数模板有两种方式：自动类型推导、显示指定类型
// * 模板的目的是为了提高复用性，将类型参数化