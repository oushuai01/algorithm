
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string fun_cc(int num, int format){
    string res;
    while(num){
        int yu = num % format;
        if(yu != 0){
            if(char('0' + yu) > '9'){
                res.push_back(char('A' + yu % 10));
            }
            else res.push_back(char('0' + yu));
        }
        else{
            res.push_back('0');
        }

        num = num / format;
    }

    return res;
}

int main() {
    int n,m;
    cin >> n >> m;

    string str = fun_cc(n,m);
    reverse(str.begin(), str.end());
    cout << str;

}