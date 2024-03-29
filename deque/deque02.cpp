// 给deque容器进行赋值
// **函数原型：**
// deque& operator=(const deque &deq);          //重载等号操作符
// assign(beg, end);                            //将[beg, end)区间中的数据拷贝赋值给本身。
// assign(n, elem);                             //将n个elem拷贝赋值给本身。

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

//赋值操作
void test01()
{
    deque<int> deq;
    for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
    printDeque(deq);

    deque<int> deq1;
    deq1 = deq;
    printDeque(deq1);

    deque<int> deq2;
    deq2.assign(10,20);
    printDeque(deq2);

    deque<int> deq3;
    deq3.assign(deq2.begin(),deq2.end());

}
int main() {
	test01();
}
//总结：deque赋值操作也与vector相同，需熟练掌握