#ifndef _SPEECHMANAGER_H
#define _SPEECHMANAGER_H
#include<iostream>
#include "speaker.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#include <ctime>
using namespace std;


class speechManager{
    public:
    //构造函数
    speechManager();
    //析构函数
    ~speechManager();

    //菜单显示
    void show_Menu();

    //退出系统
    void exit_System();

    //比赛容器 12人
    vector<int> v1;

    //第一轮晋级人数 6人
    vector<int> v2;

    //胜出名单
    vector<int> vVictory;

    //存放编号 以及对应的 具体选手 容器
    map<int,Speaker> m_speaker;

    //初始化属性
	void initSpeech();

    //比赛轮数
    int m_index = 0;

    //创建比赛选手
    void createSpeaker();

    //打印选手信息
    void printSpeak();

    //开始比赛
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
	void speechContest();

    //显示比赛结果
	void showScore();

    //保存记录
	void saveRecord();

    

    //读取记录
	void loadRecord();

	//文件为空的标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>> m_Record;

    //显示往届得分    
    void showRecord();

    //清空记录
	void clearRecord();

};

#endif

