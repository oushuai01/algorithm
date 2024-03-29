#include "speechManage.h"
speechManager::speechManager(){
    //初始化属性
    this->initSpeech();

    //创建选手
    this->createSpeaker();

    //往届记录
    this->loadRecord();
}

speechManager::~speechManager(){

}

void speechManager::show_Menu(){
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void speechManager::exit_System(){
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void speechManager::initSpeech(){
    //容器保证为空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_speaker.clear();
    this->m_Record.clear();
    //初始化比赛轮数
    this->m_index = 1;
}

void speechManager::createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0; i < nameSeed.size(); i++){
        string name = "选手";
        name += nameSeed[i];
        Speaker sp;
        sp.m_Name = name;
        sp.m_Score[0] = 0;
        sp.m_Score[1] = 0;

        //12名选手编号
        this->v1.push_back(i + 10001);

        //选手编号 以及对应的选手 存放到map容器中
        this->m_speaker.insert(make_pair(i + 10001,sp));
    }
}

void speechManager::printSpeak(){
    for(map<int,Speaker>::iterator it = this->m_speaker.begin(); it != this->m_speaker.end(); it++){
        cout << "选手编号：" << it->first << "  姓名： "  << it->second.m_Name << "  成绩： " << it->second.m_Score[0]
        << endl;
    }
}


void speechManager::startSpeech(){
    //第一轮比赛
	//1、抽签
	speechDraw();
	//2、比赛
    speechContest();
	//3、显示晋级结果
    showScore();
	//第二轮比赛
    this->m_index++;
	//1、抽签
    speechDraw();
	//2、比赛
    speechContest();
	//3、显示最终结果
    showScore();
	//4、保存分数
    saveRecord();

    //初始化属性
    this->initSpeech();

    //创建选手
    this->createSpeaker();

    //往届记录
    this->loadRecord();
    
    cout << "本届比赛结束" << endl;
}

void speechManager::speechDraw(){
    cout << "第 << " << this->m_index << " >> 轮比赛选手正在抽签"<<endl;
	cout << "---------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
    if(this->m_index == 1){
        random_shuffle(this->v1.begin(),this->v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
    }
    else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
    cout << "---------------------" << endl;
    cout << endl;
}


void speechManager::speechContest(){
    srand((unsigned int)time(NULL));
    cout << "------------- 第"<< this->m_index << "轮正式比赛开始：------------- " << endl;
    multimap<double,int,greater<double>> groupScore;//临时容器，保存key分数 value 选手编号
    int num = 0; //记录人员数，6个为1组
    vector <int> v_Src;   //比赛的人员容器
    if (this->m_index == 1)
	{
		v_Src = v1;
	}
    else
	{
		v_Src = v2;
	}
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
        num++;
        deque<double> deq;
        for(int i = 0; i < 10; i++){
            double score = (rand()%401 + 600) / 10.f;
            deq.push_back(score);
        }
        sort(deq.begin(),deq.end(),greater<int>());//排序
        deq.pop_back();  //去掉最低分
        deq.pop_front();//去掉最高分

        double sum = accumulate(deq.begin(),deq.end(),0.0f);//获取总分
        double avg = sum / (double)deq.size();  //获取平均

        this->m_speaker[*it].m_Score[this->m_index - 1] = avg;
        //6个人一组，用临时容器保存
        groupScore.insert(make_pair(avg,*it));

        if(num % 6 == 0){
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++){
                cout << "编号：" << it->second << " 姓名： " << this->m_speaker[it->second].m_Name 
                << " 成绩： " << this->m_speaker[it->second].m_Score[m_index - 1] << endl;
            }
            int count = 0;
            //取前三名
            for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++,count++){
                if(this->m_index == 1){
                    v2.push_back(it->second);
                }
                else{
                    vVictory.push_back(it->second);
                }
            }

            groupScore.clear();
            cout << endl;
        }
    }

}


void speechManager::showScore(){
    cout << "---------第" << this->m_index << "轮晋级选手信息如下：-----------" << endl;
    vector<int> v;
	if (this->m_index == 1)
	{
		v = v2;
	}
    else
	{
		v = vVictory;
	}
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << "选手编号：" << *it << " 姓名： "  << this->m_speaker[*it].m_Name << " 得分： " 
        << m_speaker[*it].m_Score[this->m_index - 1] << endl;
    }
    cout << endl;
}

void speechManager::saveRecord(){
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);

    //将每个人数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","
			<< m_speaker[*it].m_Score[1] << ",";
	}
    ofs << endl;
    //关闭文件
	ofs.close();
    
	cout << "记录已经保存" << endl;
}

void speechManager::loadRecord(){
    ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件
    if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
    char ch;
	ifs >> ch;
    if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
    //文件不为空
	this->fileIsEmpty = false;
    ifs.putback(ch); //读取的单个字符放回去

    string data;
	int index = 0;
    while (ifs >> data){
        vector<string>v;
        int pos = -1;
		int start = 0;
        while (true)
		{
            pos = data.find(",", start); //从0开始查找 ','
            if (pos == -1)
			{
				break; //找不到break返回
			}
            string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
            v.push_back(tmp);
			start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
}


void speechManager::showRecord(){
    loadRecord();
    for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届 " <<
			"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
			"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
			"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
    }
}

void speechManager::clearRecord(){
    cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

    int select = 0;
	cin >> select;

    if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
        
		//初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届记录
		this->loadRecord();
		

		cout << "清空成功！" << endl;
    }

}