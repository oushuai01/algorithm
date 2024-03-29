/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-13 21:32:44
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-13 21:43:39
 * @FilePath: \algorithm\LiKou\debug\mem.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <memory>
#include <iostream>


//智能指针

class MyClass;

// 辅助函数，打印对象状态
void PrintObjectStatus(const std::weak_ptr<MyClass>& weakPtr) {
    std::shared_ptr<MyClass> sharedPtr = weakPtr.lock();
    if (sharedPtr) {
        std::cout << "Object is still alive." << std::endl;
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }
}

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }

    void DoSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // 使用 std::weak_ptr 观察对象状态
    PrintObjectStatus(weakPtr);

    sharedPtr->DoSomething();

    // 释放 sharedPtr，对象仍然存在
    sharedPtr.reset();

    // 使用 std::weak_ptr 再次观察对象状态
    PrintObjectStatus(weakPtr);

    // 对象已被销毁，无法通过 weakPtr 访问
    std::shared_ptr<MyClass> sharedPtr2 = weakPtr.lock();
    if (sharedPtr2) {
        sharedPtr2->DoSomething();
    } else {
        std::cout << "Object is no longer available." << std::endl;
    }

    return 0;
}