#include "speechManage.h"
#include "speaker.h"
#include <iostream>
using namespace std;
int main(){
    //setlocale(LC_ALL,"");
    speechManager speech;
    //speech.show_Menu();
    int choice = 0;
    while(true){
        speech.show_Menu();
        //speech.printSpeak();
        cout << "输入你的选项" << endl;
        cin >> choice;

        switch(choice){
            case 1://开始演讲比赛
            speech.startSpeech();
            break;

            case 2://查看往届记录
            speech.showRecord();
            break;

            case 3://清空比赛记录
            speech.clearRecord();
            break;

            case 0://退出系统
            speech.exit_System();
            break;

            default:system("cls");
            break;
        }
    }
}