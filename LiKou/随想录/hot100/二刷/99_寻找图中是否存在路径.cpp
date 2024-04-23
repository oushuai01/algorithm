#include <iostream>
#include <vector>
using namespace std;
// 2024-04-22

int n = 200005;
vector<int> father = vector<int>(n, 0);

void init(){
    for(int i = 0; i < father.size(); i++)
    father[i] = i;
}


int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
}

bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    father[v] = u;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    init();

    // 将它加入集合
    for(int i = 0; i < edges.size(); i++)
    join(edges[i][0], edges[i][1]);


    return isSame(source, destination);

}