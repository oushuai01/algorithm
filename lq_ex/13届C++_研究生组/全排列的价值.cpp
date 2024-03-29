#include <iostream>
using namespace std;

int main(){
    long long n;

    cin >> n;
    long long jie = 1;
    long long sum = (n - 1) * n / 2;
    // 先要把 2 乘进去  不能最后除  所以从 3 开始
    for(long long i = 3; i <= n; i++){
        sum *= i;
        sum %= 998244353;
    }
    cout << sum;
    return 0;
}