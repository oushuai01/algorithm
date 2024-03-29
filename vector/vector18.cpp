//vector预留空间
//减少vector在动态扩展容量时的扩展次数
//**函数原型：**
// reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。
#include <vector>
#include <iostream>
using namespace std;

void printV(vector<int> & v){
    int *p = NULL;
    int num;
    cout << "初始化完成之后的size:" << v.size() << endl;
    cout << "初始化完成之后的capacity:" << v.capacity() << endl;
    for (size_t i = 0; i < 1000; i++)
    {
        v.push_back(i*2);
        if(p != &v[0]){
            p = &v[0];
            num++;
        }
    }
    cout << endl;
    cout << "加完数据size:" << v.size() << endl;
    cout << "加完数据capacity:" << v.capacity() << endl;
    cout << "地址变动次数:" << num << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
}
void test01(){
    vector<int> v;
    //预留空间
    v.reserve(100);   //预留位置不初始化，元素不可访问。预留的足够  就不需要扩容  扩容就可能换位置
    printV(v);

}

int main(){
   test01();
}

//总结：如果数据量较大，可以一开始利用reserve预留空间