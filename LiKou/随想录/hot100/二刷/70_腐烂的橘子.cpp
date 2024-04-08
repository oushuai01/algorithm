#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2024-04-08
// bfs
int orangesRotting(vector<vector<int>>& grid) {
    int cnt = 0;
    queue<vector<int>> que;
    // 将腐烂橘子加入队列  记录有多少好的橘子
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 2){
                que.push({i,j});
            }
            else if(grid[i][j] == 1){
                cnt++;
            }

        }
    }
    int ans = 0;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    while(!que.empty()){
        auto cur = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            int nextx = cur[0] + dir[i][0];
            int nexty = cur[1] + dir[i][1];

            if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;

            if(grid[nextx][nexty] != 1) continue;

            // 将腐烂橘子的值 设置为上一个腐烂橘子值 + 1 (向外扩展)
            // 这样 grid[nextx][nexty] - 2 就表示为天数
            grid[nextx][nexty] = grid[cur[0]][cur[1]] + 1;
            cnt--;

            que.push({nextx, nexty});

            ans = grid[nextx][nexty] - 2;
        }
    }

    return cnt == 0 ? ans : -1;
}

// dfs
vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
int ans = 0;
void dfs(vector<vector<int>>& grid, int x, int y){
    for(int i = 0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
        // grid[nextx][nexty] < (grid[x][y] + 1) 表示从别处腐烂橘子更新到这时间更短就需要更新它(覆盖)
        // (初始腐烂橘子不止一个)
        if(grid[nextx][nexty] != 1 && grid[nextx][nexty] < (grid[x][y] + 1)) continue;
        
        grid[nextx][nexty] = grid[x][y] + 1;
        dfs(grid, nextx, nexty);
    }
}

int orangesRotting_(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 2){
                dfs(grid, i, j);
            }
        }
    }
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1) {
                return -1;
                break;
            }
            ans = max(ans, grid[i][j]);
        }
    }
    return (ans - 2) < 0 ? 0 : ans - 2;
}


