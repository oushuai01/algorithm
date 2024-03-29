//对deque容器的大小进行操作
// **函数原型：**
// deque.empty();                         //判断容器是否为空
// deque.size();                          //返回容器中元素的个数
// deque.resize(num);                     //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
//   ​			                                    //如果容器变短，则末尾超出容器长度的元素被删除。
// deque.resize(num, elem);               //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//   ​                                             //如果容器变短，则末尾超出容器长度的元素被删除。

#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d) 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

//大小操作
void test01(){
    deque<int> deq;
    for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
    printDeque(deq);

    if(deq.empty()){
        cout << "deq为空";
    }
    else{
        cout << "deq不为空" << endl;
        //统计大小
        cout << "deq的size为：" << deq.size() << endl;
    }

    deq.resize(15,10);
    printDeque(deq);

    deq.resize(5);
    printDeque(deq);

}

int main(){
    test01();
}
// 总结：
// * deque没有容量的概念      没有capacity
// * 判断是否为空   --- empty
// * 返回元素个数   --- size
// * 重新指定个数   --- resize