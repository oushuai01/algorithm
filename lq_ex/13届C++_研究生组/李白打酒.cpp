#include <iostream>
using namespace std;
int n,m;
int count = 0;

void dfs(int index, int k, int dian, int hua){
    if(dian > n || hua > m){
        return;
    }
    if(index == (n + m - 1)){
        if(k == 1 && dian == n && hua == (m - 1)){
            count++;
        }
        return;
    }
    if(k <= 0) return;

    dfs(index + 1, k + k, dian + 1,hua);
    dfs(index + 1, k - 1, dian, hua + 1);

}
int main(){
    cin >> n >> m;
    dfs(0,2,0,0);
    cout << count;


}