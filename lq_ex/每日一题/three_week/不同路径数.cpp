#include <iostream>
#include <vector>
#include <set>
using namespace std;


vector<vector<int>> vec(10, vector<int>(10, 0));
// 这个用int也行  k值不大
// k值大了就得用字符串
set<string> ss;
int n,m,k;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void dfs(int u, int x, int y, string z){
    if(u == k + 1){
        // cout << z << endl;
        ss.insert(z);
        return;
    }
    else{
        for(int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            // x 对应的是行 也就是小于n   y对应的是列  也就是小于m
            if(tx >= 0 && ty >= 0 && tx < n && ty < m)
            dfs(u+1, tx, ty, z + to_string(vec[tx][ty]));
            // dfs(u+1, tx, ty, z*10 + vec[tx][ty]);
            else
            continue;
        }

    }
}


int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
        cin >> vec[i][j];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            dfs(1,i, j, to_string(vec[i][j]));
            // dfs(1,i, j, vec[i][j]);
        }
    }
    cout << ss.size();
    return 0;
}