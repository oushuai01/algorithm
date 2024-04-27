#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // 值捕获 x，引用捕获 y
    auto func1 = [x, &y]() {
        std::cout << "x (by value): " << x << std::endl;
        std::cout << "y (by reference): " << y << std::endl;
    };

    // 通用捕获 x 和 y
    auto func2 = [&x, y = std::move(y)]() mutable {
        std::cout << "x (by reference): " << x << std::endl;
        std::cout << "y (by move): " << y << std::endl;
    };

    x = 100; // 修改外部变量 x 的值
    y = 200; // 修改外部变量 y 的值

    func1(); // 输出 x=10, y=200
    func2(); // 输出 x=100, y=20

    return 0;
}
