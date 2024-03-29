#include <iostream>
#include <vector>
using namespace std;


int main(){

    int n, k;
    cin >> n >> k;


    string str;
    cin >> str;

    int count = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'M' || str[i] == 'T')
        count++;
    }

    cout << min(count + k , n) << endl;


    return 0;
}