//list 赋值和交换
//给list容器进行赋值，以及交换list容器

// **函数原型：**
// assign(beg, end);            //将[beg, end)区间中的数据拷贝赋值给本身。
// assign(n, elem);              //将n个elem拷贝赋值给本身。
// list& operator=(const list &lst);         //重载等号操作符
// swap(lst);                         //将lst与本身的元素互换。


#include <list>
#include <iostream>
using namespace std;

void printList(const list<int> &L){
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
//赋值和交换
void test01(){
    list<int> L1;
    L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

    //赋值
    list<int> L2;
    L2.assign(L1.begin(),L1.end());
    printList(L2);

    list<int> L3;
    L3 = L2;
    printList(L3);

    list<int> L4;
    L4.assign(10,100);
    printList(L4);
}

void test02(){
    
    list<int> L1;
    L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
    printList(L1);

    list<int> L2;
    L2.push_back(1);
	L2.push_back(5);
	L2.push_back(8);
	L2.push_back(9);

    cout << "交换前" << endl;
    printList(L1);
    printList(L2);
    cout << "交换后" << endl;
    L1.swap(L2);
    printList(L1);
    printList(L2);
}
int main(){
    test01();
    test02();
}
//总结：list赋值和交换操作能够灵活运用即可