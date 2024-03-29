//向deque容器中插入和删除数据

// **函数原型：**
// 两端插入操作：
// push_back(elem);          //在容器尾部添加一个数据
// push_front(elem);        //在容器头部插入一个数据
// pop_back();                   //删除容器最后一个数据
// pop_front();                 //删除容器第一个数据

// 指定位置操作：
// insert(pos,elem);         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
// insert(pos,n,elem);     //在pos位置插入n个elem数据，无返回值。
// insert(pos,beg,end);    //在pos位置插入[beg,end)区间的数据，无返回值。
// clear();                           //清空容器的所有数据
// erase(beg,end);             //删除[beg,end)区间的数据，返回下一个数据的位置。
// erase(pos);                    //删除pos位置的数据，返回下一个数据的位置。

#include <deque>
#include <iostream>
using namespace std;

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
//两端操作
void test01()
{
    deque<int> deq;
    //尾插
    deq.push_back(10);
    deq.push_back(20);

    //头插
    deq.push_front(12);
    deq.push_front(13);

    printDeque(deq);

    //头删
    deq.pop_front();

    //尾删
    deq.pop_back();

    printDeque(deq);
}

//插入
void test02()
{
    deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_front(20);
    deq.push_front(30);
    printDeque(deq);

    deq.insert(deq.begin(),1000);
    printDeque(deq);

    deq.insert(deq.begin(),2,3000);
    printDeque(deq);

    deque<int> deq2;
    deq2.push_back(1);
    deq2.push_back(2);
    deq2.push_back(3);

    deq2.insert(deq2.begin(),deq.begin(),deq.end());
    printDeque(deq2);

}
//删除
void test03(){
    deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
    printDeque(d);

    d.erase(d.begin());
	printDeque(d);

    d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}
int main() {
    test01();
    test02();
    test03();
}

// 总结：
// * 插入和删除提供的位置是迭代器！
// * 尾插   ---  push_back
// * 尾删   ---  pop_back
// * 头插   ---  push_front
// * 头删   ---  pop_front