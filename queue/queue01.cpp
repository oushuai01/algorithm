//queue队列
//Queue是一种**先进先出**(First In First Out,FIFO)的数据结构，它有两个出口
//队列容器允许从一端新增元素，从另一端移除元素
//队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
//队列中进数据称为 --- **入队**    `push`
//队列中出数据称为 --- **出队**    `pop`


// queue 常用接口
// 功能描述：栈容器常用的对外接口

// 构造函数：
// queue<T> que;                      //queue采用模板类实现，queue对象的默认构造形式
// queue(const queue &que);           //拷贝构造函数

// 赋值操作：
// queue& operator=(const queue &que);          //重载等号操作符

// 数据存取：
// push(elem);                               //往队尾添加元素
// pop();                                    //从队头移除第一个元素
// back();                                   //返回最后一个元素
// front();                                  //返回第一个元素

// 大小操作：
// empty();           //判断堆栈是否为空
// size();              //返回栈的大小


#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Person{
    public:
        Person(string name,int age){
            this->m_Name = name;
            this->m_Age = age;
        }
    public:
        string m_Name;
        int m_Age;
};

void test01(){
    queue<Person> p;

    Person p1("os",18);
    Person p2("wk",20);
    Person p3("zx",12);
    Person p4("wg",35);

    //向队列中添加元素  入队操作
    p.push(p1);
    p.push(p2);
    p.push(p3);
    p.push(p4);
    cout << "队列大小为：" << p.size() << endl;
    ////队列不提供迭代器，更不支持随机访问	
    while(!p.empty()){
        cout << "对头" << p.front().m_Name << "  " << p.front().m_Age << endl;

        cout << "对尾" << p.back().m_Name << "  " << p.back().m_Age << endl;
        //弹出队头元素
        p.pop();
    }
    cout << "队列大小为：" << p.size() << endl;
}
int main(){
    test01();
}
// 总结：
// - 入队   --- push
// - 出队   --- pop
// - 返回队头元素   --- front
// - 返回队尾元素   --- back
// - 判断队是否为空   --- empty
// - 返回队列大小   --- size
