#include <iostream>

int main() {
    int num1 = 10;
    int num2 = 20;

    int& ref = num1; // 创建一个引用，绑定到 num1
    std::cout << "初始绑定的值为: " << ref << std::endl;

    ref = num2; // 尝试将引用 ref 重新赋值为 num2
    std::cout << "尝试重新赋值后的值为: " << ref << std::endl;

    return 0;
}