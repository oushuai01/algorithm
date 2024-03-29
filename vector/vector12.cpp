//vector构造函数
//创建vector容器


// **函数原型：**
// vector<T> v;                		           //采用模板实现类实现，默认构造函数
// vector(v.begin(), v.end());                 //将v[begin(), end())区间中的元素拷贝给本身。
// vector(n, elem);                            //构造函数将n个elem拷贝给本身。
// vector(const vector &vec);                  //拷贝构造函数。


#include <vector>
#include <iostream>
using namespace std;


void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test01(){
    vector<int> v; //无参构造
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    printVector(v);

    vector<int> v2(v.begin(),v.end());
    printVector(v2);

    vector<int> v3(10,50);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);


}

int main() {

	test01();
}

//**总结：**vector的多种构造方式没有可比性，灵活使用即可