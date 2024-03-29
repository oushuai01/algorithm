#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<string> tiangan = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
    vector<string> dizhi = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
    int year, year_1900 = 1900;
    cin >> year;
    int cha_ , tiangan_cha, dizhi_cha;
    if(abs(year_1900 - year) % 60 == 0)
    cout << "gengzi";
    else if(year > year_1900){
        cha_ = (year - year_1900) % 60;
        tiangan_cha = cha_ % 10;
        dizhi_cha= cha_ % 12;
        cout << tiangan[(6 + tiangan_cha) % 10] << dizhi[(0 + dizhi_cha) % 12];
    }
    else if(year < year_1900){
        cha_ = (year_1900 - year) % 60;
        tiangan_cha = cha_ % 10;
        dizhi_cha= cha_ % 12;
        cout << tiangan[10 - (4 + tiangan_cha) % 10] << dizhi[12 - (12 + dizhi_cha) % 12];
    }
}



