#include <iostream>
using namespace std;

const int N = 200010;
int arr[N];
int front_sum[N];
long long sum;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d",&arr[i]);
        front_sum[i] += front_sum[i - 1];
    }
    for(int i = 1; i <= n; ++i){
        sum += (front_sum[n] - front_sum[i]) * arr[i];
    }
    cout << sum;
    return 0;
}