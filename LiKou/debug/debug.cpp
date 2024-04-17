#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<vector<int>> maze;
vector<vector<int>> path_best;
vector<vector<int>> path_temp;//临时的辅助路径

void bestpath(int i,int j){
    //如果进来，走过就不走了
    maze[i][j]=1;
    
    //存进去
    path_temp.push_back({i,j});

    //判断出去的条件
    if(i == N-1 && j == M-1){
        if(path_temp.size() < path_best.size() || path_best.empty()){
            path_best = path_temp;
        }
    }

    //开始走 上、下、左、右
    if(i-1 >= 0 && maze[i-1][j]==0){
        bestpath(i-1,j);
    }
    if(i+1 < N && maze[i+1][j] == 0){
        bestpath(i+1,j);
    }
    if(j-1 >= 0 && maze[i][j-1] == 0){
        bestpath(i,j-1);
    }
    if(j+1 < M && maze[i][j+1] == 0){
        bestpath(i,j+1);
    }

    //如果没进循环，标记回去
    maze[i][j]=0;
    path_temp.pop_back();
}

int main() {
    while (cin >> N >> M) { // 注意 while 处理多个 case
        //赋值
        maze = vector<vector<int>>(N,vector<int>(M,0));
        //清空
        path_best.clear();
        path_temp.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>maze[i][j];
            }
        }

        //递归回溯
        bestpath(0,0);

        //输出
        for(auto itor:path_best){
            cout<<"("<<itor[0]<<","<<itor[1]<<")"<<endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")