#include <iostream>
using namespace std;

const int N = 1000;
int n = 3;
bool st[N];
int Path[N];

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; ++i)
        cout << Path[i] << " ";
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; ++i){
        if(!st[i]){
            Path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main(){
    
    dfs(0);
    return 0;
}