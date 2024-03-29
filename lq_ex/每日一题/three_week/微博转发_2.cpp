#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// 邻接表的做法

const int N = 1005, M = 10e5 + 10;

int h[N],e[M],ne[M],idx;
bool st[N];
int n,l;

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs(int x){
    queue<int> que;
    // 点没有被扩展过
    memset(st, 0, sizeof(st));
    que.push(x);
    st[x] = true;
    int res = 0;

    for(int i = 0; i < l; ++i){
        int size_ = que.size();
        while(size_--){
            int t = que.front();
            que.pop();
            // 最后一个数字的 ne 是 -1
            for(int j = h[t]; j != -1; j = ne[j]){
                int x = e[j];
                if(!st[x]){
                    que.push(x);
                    st[x] = true;
                    res++;
                }
            }
        }
    }
    return res;

}

int main(){
    memset(h, -1, sizeof(h));
    idx = 0;
    cin >> n >> l;

    for(int i = 1; i <=n; ++i){
        int x;
        cin >> x;
        for(int j = 0; j < x; ++j){
            int people;
            cin >> people;
            add(people,i);
        }
    }

    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        cout << bfs(x) << endl;
    }


}