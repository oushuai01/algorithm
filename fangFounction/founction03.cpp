// 二元谓词
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

bool cmp(int num1, int num2){
    return num1 > num2;
}

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
    //默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

    //使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
    // sort(v.begin(),v.end(),cmp);   这个也行
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main() {

	test01();
}
//总结：参数只有两个的谓词，称为二元谓词
