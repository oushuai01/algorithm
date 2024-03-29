#include <iostream>
using namespace std;

int main(){
   int num;
    cin >> num;
    int jige = 0;
    int youxiu = 0;
    int socre;
    for(int i = 0; i < num; ++i){
        cin >> socre;
        if(socre >= 60){
            jige++;
        }
        if(socre >=85){
            youxiu++;
        }
    }
    int jige_av = (int)((double(jige) / num)*1000);
    int youxiu_av = (int)((double(youxiu) / num)*1000);
    if(jige_av % 10 >= 5)
    jige_av = jige_av/10 + 1;
    else
    jige_av = jige_av/10;
    if(youxiu_av % 10 >= 5)
    youxiu_av = youxiu_av/10 + 1;
    else
    youxiu_av = youxiu_av/10;
    cout << jige_av << "%" << endl << youxiu_av << "%" ;
}