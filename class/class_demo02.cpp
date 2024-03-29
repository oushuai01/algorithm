#include <iostream>
#include "string.h"
using namespace std;
//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
// 银行卡账号--protected   密码 ---  private
//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问
class Student{
    public:
            string m_name;
            int m_id;


            void setName(string name){
                m_name = name;
            }
            void setID(int ID){
                m_id = ID;
            }
            void showStudent(){
                cout << "name = " << m_name << endl;
                cout << "id = " << m_id << endl;
            }
    protected:
              int yhk_id = 123456;  //银行卡账号
    private:
              int password = 111222;  //银行卡密码

};
int main(){
    Student stu;
    stu.setName("os");
    stu.setID(110);
    stu.showStudent();

    return 0;
}