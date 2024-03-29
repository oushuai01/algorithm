#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N = 1000010;
vector<int> a(N,0);
vector<int> b(N,0);

bool cmp(int &x,  int &y){
    if(b[x] != b[y])
    return b[x] < b[y];
    else
    return x < y;
}

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; ++i){
        int num = i;
        while(num){
            b[i] += num % 10;
            num /= 10;
        }
        a[i] = i;
    }
    // 要到最后一位
    sort(a.begin() + 1,a.begin() + n + 1, cmp);
    cout << a[m];
    return 0;
}