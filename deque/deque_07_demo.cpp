// 案例描述
// 有5名选手：选手ABCDE，
// 10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

// 实现步骤
// 1. 创建五名选手，放到vector中
// 2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
// 3. sort算法对deque容器中分数排序，去除最高和最低分
// 4. deque容器遍历一遍，累加总分
// 5. 获取平均分

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Person{
    public:
        Person(string name, double score){
            this->m_Name = name;
            this->m_score =score;
        }
    public:
        string m_Name;
        double m_score;
};

void creatPerson(vector<Person> &v){
    string name = "ABCDE";
    for(int i = 0; i < name.size(); i++){
        string name_x = "选手";
        name_x = name_x + name[i];
        double score = 0;
        Person p(name_x,score);

        //将创建的person对象 放入到容器中
        v.push_back(p);
    }
}

void setScore(vector<Person> &v){
    for(int i = 0; i < v.size(); i++){
        //存下10个分数
        //cout << v[i].m_Name << endl;   //打印名字
        deque<double> deq;
        for(int i = 0; i < 10; i++){
            double score = rand() %41 + 60;    //60-100;
            //cout << i << " " << score << endl;   //打印每个分数
            deq.push_back(score);
        }
        //排序
        sort(deq.begin(),deq.end());

        //去掉最高和最低
        deq.pop_front();
        deq.pop_back();

        double sum = 0;
        for(int i = 0; i < deq.size(); i++){
            sum += deq[i];
        }
        //平均分
        double avg = sum/deq.size();

        v[i].m_score = avg;
    }
}
  void show(vector<Person> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i].m_Name << "  " << v[i].m_score << endl;
    }
    cout << endl;
  }
//自定义排序方式
bool cmp1(Person p1,Person p2){
    return p1.m_score < p2.m_score;    //按照分数排序  《 从小到大 
                                       //              》 从大到小
}

bool cmp2(Person p1,Person p2){
    return p1.m_score > p2.m_score;    //按照分数排序  《 从小到大 
                                       //              》 从大到小
}

  int main(){
    vector<Person> person;
    creatPerson(person);
    setScore(person);
    show(person);
    //排序后的person
    cout << "分数从小到大" << endl;
    sort(person.begin(),person.end(),cmp1);   //按照分数从小到大
    show(person);
    cout << "分数从大到小" << endl;
    sort(person.begin(),person.end(),cmp2);   //按照分数从大到小
    show(person);
  }
  
  //**总结：** 选取不同的容器操作数据，可以提升代码的效率


