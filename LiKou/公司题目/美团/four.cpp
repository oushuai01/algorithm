/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-16 15:54:24
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-25 15:22:42
 * @FilePath: \algorithm\LiKou\公司题目\美团\four.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n , m , q;
unordered_map<int, vector<int>> umap;

void gx_fun(unordered_map<int, vector<int>> &umap_){
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(umap_[i][j] == 0) continue;
           else
        }
    }
}

int main(){
    cin >> n >> m >> q;
    vector<string> vec;
    
    for(int i = 1; i <= n; i++){
        umap[i] = vector<int>(n + 1, 0);
    }

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        umap[u][v] = 1;
        umap[v][u] = 1;
        //cout << umap[u][v] << " " << umap[u][v] << endl;
    }


    gx_fun(umap);

    for(int i = 1; i <= q; i++){
        int op, u , v;
        cin >> op >> u >> v;

        if(op == 1){
            umap[u][v] = 0;
            umap[v][u] = 0;
            gx_fun(umap);
        }else if(op == 2){
            if(umap[u][v] == 1)
            vec.push_back("Yes");
            else
            vec.push_back("No");
        }
    }

    for(string str : vec){
        cout << str << endl;
    }
    


}



