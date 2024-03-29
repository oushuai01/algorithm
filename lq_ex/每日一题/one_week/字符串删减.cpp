#include <iostream>
using namespace std;

int main(){
    int n,count = 0,ea_count = 0;
    string str;
    cin >> n;
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 'x'){
            count++;
            if(count >= 3){
                ea_count++;
                count--;
            }
        }
        if(str[i] != 'x'){
            count = 0;
        }
    }
    cout << ea_count;


    return 0;
}