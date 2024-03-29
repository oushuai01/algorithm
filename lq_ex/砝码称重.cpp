#include <iostream>
#include <math.h>
using namespace std;
const int N = 110, M = 100010;
int n;
int arr[N];
bool sum_[M];
bool st[N][M];
int ans = 0;

// dfs + 记忆搜索
void dfs(int u, int sum){
    if(st[u][sum]) return;
    st[u][sum] = true;
    sum_[sum] = true;
    
    if(u > n) return;
    
    dfs(u+1, sum + arr[u]);
    dfs(u+1, sum);
    dfs(u+1, abs(sum - arr[u]));
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    dfs(1,0);
    for(int i = 1; i < M; ++i)
    if(sum_[i])
    ans++;
    
    cout << ans;
    
}