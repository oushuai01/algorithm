//谓词
//返回bool类型的仿函数称为**谓词**
//如果operator()接受一个参数，那么叫做一元谓词
//* 如果operator()接受两个参数，那么叫做二元谓词

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct GreterFive
{
    bool operator()(int val){
        return val > 5;
    }
};
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreterFive());
    if (it == v.end()) {
		cout << "没找到!" << endl;
	}
	else {
		cout << "找到:" << *it << endl;
	}
}
int main() {

	test01();
}
//总结：参数只有一个的谓词，称为一元谓词