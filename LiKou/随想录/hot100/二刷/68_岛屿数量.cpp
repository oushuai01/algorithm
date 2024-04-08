#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2024-04-07

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
// 深度优先搜索
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
    // 被访问过或者不是陆地 直接返回
    if(visited[x][y] || grid[x][y] == '0') return;
    visited[x][y] = true;

    // 遍历4个方向
    for(int i = 0; i < 4; i++){
        int Nextx = x + dir[i][0];
        int Nexty = y + dir[i][1];
        if(Nextx >= grid.size() || Nexty >= grid[x].size() || Nextx < 0 || Nexty < 0) continue;
        dfs(grid, visited, Nextx, Nexty);
    }
}

// 广度优先搜索
void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
    queue<pair<int,int>> que;
    que.push({x, y});
    visited[x][y] = true; // 只要加入队列，立刻标记
    while(!que.empty()){
        pair<int,int> xy = que.front();
        que.pop();
        int curx = xy.first;
        int cury = xy.second;

        for(int i = 0; i < 4; i++){
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if(nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;

            if(!visited[nextx][nexty] && grid[nextx][nexty] == '1'){
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
    }
}



int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    vector<vector<bool>> visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                result++;
                dfs(grid, visited, i, j);
            }
        }
    }

    return result;
}