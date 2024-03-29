//关系仿函数
//实现关系对比
// **仿函数原型：**
// template<class T> bool equal_to<T>                    //等于
// template<class T> bool not_equal_to<T>            //不等于
// template<class T> bool greater<T>                      //大于
// template<class T> bool greater_equal<T>          //大于等于
// template<class T> bool less<T>                           //小于
// template<class T> bool less_equal<T>               //小于等于

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyCompare{
    public:
        bool operator()(int val1,int val2){
            return val1 > val2;
        }
};

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

    //自己实现仿函数
	//sort(v.begin(), v.end(), MyCompare());

    //STL内建仿函数  大于仿函数
    sort(v.begin(),v.end(),greater<int>());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();
}
//总结：关系仿函数中最常用的就是greater<>大于