#include <iostream>
using namespace std;
int main(){

    /*
        引用
        **作用：给变量起别名
        **语法：数据类型 &别名 = 原名
    */
   int a =10;
   int &b = a;

   cout << "a = " << a << endl;
   cout << "b = " << b << endl;

   b = 100;

   cout << "a = " << a << endl;    //100
   cout << "b = " << b << endl;    //100


   //引用必须初始化
   //引用在初始化后，不可以改变
   int d = 5;
   int e = 8;
   //int &f; //错误，引用必须初始化
   int &f = d;  //一旦初始化后，就不可以更改
   cout << "f = " << f << endl;

   f = e;   //这是赋值操作，不是更改引用
   cout << "d = " << d << endl;
   cout << "f = " << f << endl;
   cout << "e = " << e << endl;

   return 0;
}