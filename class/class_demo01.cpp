#include <iostream>

using namespace std;
//设计一个圆类，求圆的周长
const double PI = 3.14;

//封装一个圆类  求圆的周长
//class代表设计一个类  后面跟着的是类名
class Circle{
    public:
        int m_r;    //半径
        double calculateZC(){
            return 2 * PI * m_r;
        }
        Circle(){
            cout << "os" << endl;
        }
};




int main(){
    
    Circle c1;
    c1.m_r = 10;   //圆的半径
    cout << "Circle =  " << c1.calculateZC() << endl;    //输出圆的周长

    system("pause");
    return 0;
}