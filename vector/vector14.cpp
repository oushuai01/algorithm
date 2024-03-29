// vector容量和大小
// 对vector容器的容量和大小操作
// empty();                             //判断容器是否为空
// capacity();                          //容器的容量
// size();                              //返回容器中元素的个数
// resize(int num);                     //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
//   ​					                 //如果容器变短，则末尾超出容器长度的元素被删除。
// resize(int num, elem);               //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
//   ​				                     //如果容器变短，则末尾超出容器长度的元素被删除

// 容器要是扩容或者增加数据  有可能直接存在预留空间(更快)   也有可能扩容之后再放新元素(更慢一些)
#include <vector>
#include <iostream>
using namespace std;
void printVector(vector<int> &v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
   //cout << v1.data() << endl;     //打印v1的首地址
	printVector(v1);

    if(v1.empty())
        cout << "v1为空" << endl; 
    else{
        cout << "v1不为空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl;
		cout << "v1的大小 = " << v1.size() << endl;
    }
    //resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(30,0);
    printVector(v1);
    //resize 重新指定大小 ，若指定的更小，超出部分元素被删除
    v1.resize(5);
    printVector(v1);
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;

    v1.reserve(50);  //指定容量大小   只能大
    printVector(v1);
    //cout << v1.data() << endl;
    cout << v1.capacity() << endl;

}

int main(){
    test01();
}

// * 判断是否为空  --- empty
// * 返回元素个数  --- size
// * 返回容器容量  --- capacity
// * 重新指定大小  ---  resize

