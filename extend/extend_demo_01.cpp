#include <iostream>
#include "string.h"
using namespace std;


class A{
    public:
    virtual void test(){
        cout << "A test" << endl;
    }
    void cnn(){
        test();
        cout << "CNN" << endl;
    }
};

class B : public A{
    public:
    void test(){
        cout << "B test" << endl;
    }
};

int main(){
   A* a = new B;
   a->cnn();
}