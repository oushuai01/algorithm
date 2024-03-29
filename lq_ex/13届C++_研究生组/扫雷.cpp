#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 50010, M = 500011;
const LL X = 1e9 + 1;
LL h[M];
bool st[N];
int id[M];

struct xyr
{
    LL x;
    LL y;
    int r;
    
}syr[N];

LL get_hsvalue(LL x,LL y){
    return x * X + y;
}

int get_key(LL x, LL y){
    LL hs = get_hsvalue(x,y);
    int key = (hs % M + M) % M;
    while(h[key] != -1 && h[key] != hs){
        key++;
        if(key == M) key = 0;
    }
    return key;
}
bool cheak(LL x, LL y, int r, LL xx, LL yy){
    LL d = (xx - x) * (xx - x) + (yy - y) * (yy -y);
    return d <= r * r;

}

void dfs(int pos){
    queue<int> que;
    que.push(pos);
    while(que.size()){
        int top = que.front();
        que.pop();
        st[top] = true;
        LL x = syr[top].x, y = syr[top].y;
        int r = syr[top].r;
        for(LL xx = x - r; xx <= x + r; ++xx){
            for(LL yy = y - r; yy <= y + r; ++yy){
                int key = get_key(xx,yy);
                if(id[key] && cheak(x,y,r,xx,yy) && !st[id[key]]){
                    que.push(id[key]);
                    st[id[key]] = true;
                }
            }
        }

    }
}


int main(){
    int n,m;
    memset(h, -1, sizeof(h));
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; ++i){
        scanf("%lld%lld%d",&syr[i].x, &syr[i].y, &syr[i].r);
        int key = get_key(syr[i].x ,syr[i].y);
        if(h[key] == -1) h[key] = get_hsvalue(syr[i].x,syr[i].y);
        // 是同一个点  但是r比较大
        if(!id[key] || syr[id[key]].r < syr[i].r){
            id[key] = i;
        }
        // cout << id[key] << endl;
    }

    for(int i = 1; i <= m; ++i){
        LL x,y;
        int r;
        scanf("%lld%lld%d",&x, &y, &r);
        for(LL xx = x - r; xx <= x + r; ++xx){
            for(LL yy= y - r; yy <= y + r; ++yy){
                int key = get_key(xx,yy);
                if(id[key] && !st[id[key]] && cheak(x,y,r,xx,yy))
                dfs(id[key]);
            }
        }
    }
    int count  = 0;
    for(int i = 1; i <= n; ++i){
        int key = get_key(syr[i].x,syr[i].y);
        int pos = id[key];
        if(pos && st[pos]) 
        count++;
    }
    cout << count;


    return 0;
}