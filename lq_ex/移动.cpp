#include <iostream>
using namespace std;

int main(){
    string str = "DDDRRLR";
    int x = 0, y = 0;
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == 'U')
        x-=1;
        if(str[i] == 'D')
        x+=1;
        if(str[i] == 'L')
        y-=1;
        if(str[i] == 'R')
        y+=1;
    }
    cout << x << " " << y;


    return 0;
}