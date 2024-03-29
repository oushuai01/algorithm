#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2010, M = 200010;
typedef pair<int,int> PII;
int time_x[N];
int h[N],e[M],ne[M],tagert[M],idx;
int n,m,k,t;
int dist[N];
bool st[N];
queue<int> que;

priority_queue<PII,vector<PII>,greater<PII>> que_djikstra;
void add(int a, int b, int c){
    e[idx] = b;
    tagert[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}


void spfa(){
    while(que.size()){
        int x = que.front();
        que.pop();
        st[x] = false;
        for(int i = h[x]; i != -1; i = ne[i]){
            int y = e[i], z = tagert[i];
            if(dist[z] > max(dist[x],dist[y]) + max(time_x[x],time_x[y])){
                dist[z] = max(dist[x],dist[y]) + max(time_x[x],time_x[y]);
                if(!st[z]){
                    que.push(z);
                    st[z] = true;
                }
            }
        }
    }
    
}

void dijkstra(){
     while(que_djikstra.size()){
            int x = que_djikstra.top().second;
            que_djikstra.pop();
            
            if(st[x]) continue;
            st[x] = true;
            
            for(int i = h[x]; i != -1; i = ne[i]){
                int y = e[i], z = tagert[i];
                if(dist[z] > max(dist[x],dist[y]) + max(time_x[x],time_x[y])){
                    dist[z] = max(dist[x],dist[y]) + max(time_x[x],time_x[y]);
                    que_djikstra.push({dist[z],z});
                }
            }
            
     }
}

int main(){
    
    scanf("%d%d%d%d",&n,&m,&k,&t);
    for(int i = 1; i <= n ; ++i){
        scanf("%d",&time_x[i]);
    }
    
    memset(h,-1,sizeof(h));
    memset(dist,0x3f,sizeof(dist));
    while(m--){
        int x;
        scanf("%d",&x);
        que.push(x);
        st[x] = true;
        dist[x] = 0;
        // que_djikstra.push({dist[x],x});   用dijkstra 就不能先把st[x] = true;
    }
    
    while(k--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    
    spfa();
    
    printf("%d",dist[t]);
    
    
    
    return 0;
}