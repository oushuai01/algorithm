#include <iostream>
using namespace std;

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main(){


    cout << "ret = " << func2(20, 20) << endl;  //40
    cout << "ret = " << func2() << endl;   //20

	system("pause");


    return 0;
}