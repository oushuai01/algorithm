#include <iostream>
using namespace std;
//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
    // 引用做函数参数
    // 作用：函数传参时，可以利用引用的技术让形参修饰实参
    // 优点：可以简化指针修改实参

//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//返回静态变量引用   不能返回局部变量的引用
int& test02() {
	static int a = 20;
	return a;
}

//引用的本质在c++内部实现是一个指针常量.
//发现是引用，转换为 int* const ref = &a;
void func(int& ref){
	ref = 100; // ref是引用，转换为*ref = 100
}

//引用使用的场景，通常用来修饰形参  函数中利用常量引用防止误操作修改实参
void showValue(const int& v) {
	//v += 10;
	cout << v << endl;
}

int main() {

	int a = 10;
	int b = 20;

	mySwap01(a, b);
	cout << "a:" << a << " b:" << b << endl;

	mySwap02(&a, &b);
	cout << "a:" << a << " b:" << b << endl;

	mySwap03(a, b);
	cout << "a:" << a << " b:" << b << endl;

    
    //总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单
    //C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了



	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
    
    func(ref2);
    cout << "ref2 = " << ref2 << endl;

    /*
        常量引用
    
    */
    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
    //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
    const int& reff = 10;

    //reff = 100;  //加入const后不可以修改变量
	cout << reff << endl;

    //函数中利用常量引用防止误操作修改实参
	int t = 10;
	showValue(t);

	system("pause");

	return 0;
}