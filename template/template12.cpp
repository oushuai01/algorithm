// 学习目标：
// * 掌握类模板成员函数分文件编写产生的问题以及解决方式

// 问题：
// * 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到


// 解决：
// * 解决方式1：直接包含.cpp源文件
// * 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
#include <iostream>
#include <string.h>
#include "template12.hpp"
using namespace std;

void test01()
{
	Person<string, int> p("Tom", 10);
	p.showPerson();
}

int main() {

	test01();
}


//总结：主流的解决方式是将类模板成员函数写到一起，并将后缀名改为.hpp