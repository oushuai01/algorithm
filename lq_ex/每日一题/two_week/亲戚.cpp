#include <iostream>
using namespace std;
const int N = 20010;
int P[N];

int find(int x){
    if(x != P[x]) P[x] = find(P[x]);
    return P[x];
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; ++i){
        P[i] = i;
    }

    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a = find(a);
        b = find(b);
        P[b] = a;
    }

    int q;
    scanf("%d",&q);
    while(q--){
         int a,b;
        scanf("%d%d",&a,&b);
        a = find(a);
        b = find(b);
        if(a == b) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}