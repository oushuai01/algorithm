#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// 邻接矩阵的做法  复杂度O(n2)

const int N = 1010;
bool g[N][N] ,st[N];
int n, l;

int bfs(int x){
    queue<pair<int,int>> que;
    // 头文件 ctring
    memset(st, 0, sizeof(st));
    int cnt = 0;
    que.push({x,0});
    st[x] = true;
    while(que.size()){
        auto que_front = que.front();
        que.pop();
        int a = que_front.first;
        int b = que_front.second;
        for(int i = 1; i <= n; ++i){
            // 查找 i 有没有关注 a
            if(st[i] || !g[i][a])
            continue;
            st[i] = true;
            if(b + 1 <= l){
                que.push({i, b + 1});
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin >> n >> l;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        for(int j = 0; j < x; ++j){
            int follower;
            cin >> follower;
            // 设置 i 号人物关注的人物
            g[i][follower] = true;
        }
    }

    int question;
    cin >> question;
    for(int i = 0; i < question; ++i){
        int people_;
        cin >> people_;
        cout << bfs(people_) << endl;
    }

    return 0;
}