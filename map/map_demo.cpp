// #### 3.10.1 案例描述
// * 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
// * 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
// * 随机给10名员工分配部门和工资
// * 通过multimap进行信息的插入  key(部门编号) value(员工)
// * 分部门显示员工信息

//3.10.2 实现步骤
// 1. 创建10名员工，放到vector中
// 2. 遍历vector容器，取出每个员工，进行随机分组
// 3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
// 4. 分部门显示员工信息


#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <ctime>
using namespace std;
#define CHEHUA 0
#define MEISHU 1
#define YANFA 2

class Woker{
    public:
        string m_Name;
        double m_Sal;
};

void creatWoker(vector<Woker> &v){
    string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++){
        Woker woke;
        woke.m_Name = "员工";
        woke.m_Name += nameSeed[i];
        woke.m_Sal = rand()%10000 + 10000;
        v.push_back(woke);
    }
}

void setGroup(vector<Woker> &v, multimap<int,Woker> &m){
    for(vector<Woker>::iterator it = v.begin(); it != v.end(); it++){
        //产生随机部门id
        int deptID = rand()%3;     // 0 1 2

        //将员工插入到分组中
		//key部门编号，value具体员工
        m.insert(make_pair(deptID,*it));
    }
}

void showWokerByGourp(multimap<int,Woker> &m){
    cout << "策划部部门" << endl;
    multimap<int,Woker>::iterator pos = m.find(CHEHUA);
    int count = m.count(CHEHUA);
    int index = 0;
    for(multimap<int,Woker>::iterator it = pos; it != m.end() && index < count; index++,it++){
        cout << "姓名"  << it->second.m_Name << "  " << "薪资" << it->second.m_Sal << endl;
    }

    cout << "美术部部门" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for(multimap<int,Woker>::iterator it = pos; it != m.end() && index < count; index++,it++){
        cout << "姓名"  << it->second.m_Name << "  " << "薪资" << it->second.m_Sal << endl;
    }

    cout << "研发部部门" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for(multimap<int,Woker>::iterator it = pos; it != m.end() && index < count; index++,it++){
        cout << "姓名"  << it->second.m_Name << "  " << "薪资" << it->second.m_Sal << endl;
    }

}

int main(){
    //用时间来做随机数种子
    srand((unsigned)time(NULL));
    vector<Woker> woke;
    creatWoker(woke);


    multimap<int,Woker> m;
    setGroup(woke,m);

    showWokerByGourp(m);

    cout << rand()%1000;

}