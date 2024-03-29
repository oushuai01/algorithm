//pair对组创建
//成对出现的数据，利用对组可以返回两个数据
// **两种创建方式：**
// pair<type, type> p ( value1, value2 );
// pair<type, type> p = make_pair( value1, value2 );

#include <set>
#include <string>
#include <iostream>
using namespace std;

// bool cmp(pair<int,string> p1, pair<int,string> p2){
//     return p1.first > p2.first;
// }

void pringSet(set< pair<int,string> > &s){
    for(set< pair<int,string> >::iterator it = s.begin(); it != s.end(); it++){
        cout <<  (*it).first << "  " << (*it).second << " ";
    }
    cout << endl;
}

void test01()
{
    //默认按照第一个元素进行排序
    set<pair<int,string>> s;
    pair<int,string> p1(20,"os");
    pair<int,string> p2(18,"wq");
    pair<int,string> p3(19,"ws");

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);


    pringSet(s);


}

//对组创建
void test02()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " <<  p.first << " 年龄： " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

int main(){
    test01();
}

// 总结：
// 两种方式都可以创建对组，记住一种即可