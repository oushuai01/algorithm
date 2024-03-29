#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 410 , M =160010;
typedef pair<int,int> PII;
int h1[N], h2[N],e[M], ne[M], idx;
int g[N][N];
bool st[N];
int dist[N];
int n,m;

void add(int h[],int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


// spfa
int spfa(int h[], int flag){
    memset(st,false,sizeof st);
    memset(dist,0x3f,sizeof dist);
    if(flag == 0 && g[1][n] == 1 || flag == 1 && g[1][n] != 1) return 1;
    queue<int> que;
    que.push(1);
    st[1] = true;
    dist[1] = 0;
    while(que.size()){
        int x = que.front();
        que.pop();
        st[x] = false;
        for(int i = h[x]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[x] + 1){
                dist[j] = dist[x] + 1;
                if(!st[j]){
                    que.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}


// dijkstra
int dijkstra(int h[], int flag){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    if(flag == 0 && g[1][n] == 1 || flag == 1 && g[1][n] != 1) return 1;
    priority_queue<PII,vector<PII>,greater<PII>> pque;
    dist[1] = 0;
    pque.push({dist[1],1});

    while(pque.size()){
        int id = pque.top().second;
        pque.pop();

        if(st[id]) continue;
        st[id] = true;
        
        for(int i = h[id]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[id] + 1){
                dist[j] = dist[id] + 1;
                // 不需要这里判断是否被确定
                pque.push({dist[j],j});
            }
        }
    }
    return dist[n];
}



int main(){
    scanf("%d%d",&n,&m);

    memset(h1, -1, sizeof h1);
    memset(h2, -1, sizeof h2);

    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a][b] = g[b][a] = 1;
        add(h1,a,b);
        add(h1,b,a);
    }

    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[i][j] != 1 && i != j){
                add(h2,i,j);
            }
        }
    }

    int res = max(dijkstra(h1,0), dijkstra(h2,1));
    if(res > 0x3f3f3f3f / 2) res = -1;
    cout << res;

    // system("pause");
    
}