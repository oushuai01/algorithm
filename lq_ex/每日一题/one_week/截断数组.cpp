#include <iostream>
using namespace std;
const int N = 100010;
long long arr[N];

int main(){
    int n;
    int count = 1;
    cin >> n;
    if(n < 3)
    cout << 0;
    else if(n >= 3){
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        if(arr[n] % 3 != 0)
        cout << 0;
        else{
            long long sum_3 = arr[n] / 3;
            long long tot = 0;
            long long cnt = 0, res = 0;
            for(int i = 1; i < n; ++i){
                tot = arr[i];
                if(tot == sum_3 * 2) res += cnt;
                if(tot == sum_3) cnt++;
            }
            cout << res;
        }
    }
    return 0;
}