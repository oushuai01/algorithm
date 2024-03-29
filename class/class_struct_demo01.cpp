#include <iostream>
#include "string.h"
using namespace std;

//在C++中 struct和class唯一的**区别**就在于 **默认的访问权限不同**
// 区别：
// * struct 默认权限为公共
// * class   默认权限为私有
class C1
{
	int  m_A; //默认是私有权限
};

struct C2
{
	int m_A;  //默认是公共权限
};



// **优点1：**将所有成员属性设置为私有，可以自己控制读写权限

// **优点2：**对于写权限，我们可以检测数据的有效性

class Person{
    public:
        //姓名可读可写
        void setName(string name){
            m_Name = name;
        }
        string getName(){
            return m_Name;
        }

        //年龄可读可写
        void setAge(int age){
            m_Age = age;
        }
        int getAge(){
            return m_Age;
        }

        //情人只可写
        void setLover(string love){
            m_Lover = love;
        }


    private:
        string m_Name;  //可读可写  姓名
        int m_Age;      //可读可写  年龄
        string m_Lover;   // 只写  情人



};

int main(){
    Person os;
    os.setName("帅哥");
    os.setAge(20);
    os.setLover("小芳");
    cout << "name = " << os.getName() << "    " << "age = " << os.getAge() ;


    return 0;

}