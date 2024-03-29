#include <iostream>
using namespace std;

int main(){
    long long a,b;
    cin >> a >> b;
    long long cha = b - a;
    int min_ = a / cha + 1;
    cout << min_ * cha - a;
    return 0;
}