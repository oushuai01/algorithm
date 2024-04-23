#include <iostream>
#include <vector>
using namespace std;

int N = 1005;
vector<int> father = vector<int>(N, 0);
int n = 0;

void init(){
    for(int i = 0; i <= n; i++){
        father[i] = i;
    }
}

int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]);
}

bool isSame(int u, int v){
    u = find(u);
    v = find(v);

    return u == v;
}

// u -> v
void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;

    father[u] = v;
}


bool isTreeAfterRemove(vector<vector<int>>& edges, int index){
    for(int i = 0; i < n; i++){
        if(i == index) continue;

        if(isSame(edges[i][0], edges[i][1])) return false;

        join(edges[i][0], edges[i][1]);
    }
    return true;
}

vector<int> Remove(vector<vector<int>>& edges){
    for(int i = 0; i < n; i++){
        if(isSame(edges[i][0], edges[i][1])) return edges[i];

        join(edges[i][0], edges[i][1]);
    }

    return {};
}






vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    n = edges.size();
    vector<int> indgreen = vector<int>(N, 0);
    vector<int> vec;
    init();

    for(int i = 0; i < n; i++){
        indgreen[edges[i][1]]++;  // 统计入度
    }
    cout << "indgreen: ";
    // 记录入度为2的边
    for(int i = n - 1; i >= 0; i--){
        if(indgreen[edges[i][1]] == 2){
            vec.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;

    // 如果有入度为2的节点
    // 那么一定是两条边里删一个，看删哪个可以构成树
    if(vec.size() > 0){
        if(isTreeAfterRemove(edges, vec[0])) {
            cout << "isTreeAfterRemove -- true" << endl;
            return edges[vec[0]];
        }
        else {
            cout << "isTreeAfterRemove -- false" << endl;
            return edges[vec[1]];
        }
    }

    // 明确没有入度为2的情况
    // 那么一定有有向环，找到构成环的边返回就可以了
    return Remove(edges);
}



int main(){
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    for(auto num : findRedundantDirectedConnection(edges)){
        cout << num << " ";
    }
    //cout << findRedundantDirectedConnection(edges);
}