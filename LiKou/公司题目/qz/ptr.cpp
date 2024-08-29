#include <atomic>
#include <iostream>
#include <thread>
#include <memory>
using namespace std;


class MyObject {
public:
    void doSomething(){
        cout << "do something" << endl;
    }
};


int main(){
    std::atomic<shared_ptr<MyObject>> ptr;
    std::shared_ptr<MyObject> obj = make_shared<MyObject>();

    ptr.store(obj);
    std::thread t1([&ptr](){
        auto p = ptr.load();
        if(p) p->doSomething();
    });

    std::thread t2([&ptr](){
        auto p = ptr.load();
        if(p) p->doSomething();
    });

    t1.join();
    t2.join();
}



