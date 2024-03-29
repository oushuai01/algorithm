//deque容器基本概念
//双端数组，可以对头端进行插入删除操作


//deque构造函数
// 函数原型：
// deque<T> deqT;                     //默认构造形式
// deque(beg, end);                   //构造函数将[beg, end)区间中的元素拷贝给本身。
// deque(n, elem);                    //构造函数将n个elem拷贝给本身。
// deque(const deque &deq);           //拷贝构造函数

#include <deque>
#include <iostream>
using namespace std;
void printDeque(const deque<int> &deq){
    for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){    //const_iterator 表示只读  不能修改
        cout << *it << " ";
    }
    cout << endl;
}

void printDeque02(deque<int> &deq){
    for(deque<int>::iterator it = deq.begin(); it != deq.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
//deque构造
void test01(){
    //无参构造
    deque<int> deq;
    for(int i = 0; i < 10; i++){
        deq.push_back(i);
    }
    printDeque(deq);

    deque<int> deq2(deq.begin(),deq.end());
    printDeque(deq2);

    deque<int> deq3(10,100);
    printDeque(deq3);

    deque<int> deq4 = deq3;
	printDeque(deq4);
}

int main(){
     test01();
}
//**总结：**deque容器和vector容器的构造方式几乎一致，灵活使用即可