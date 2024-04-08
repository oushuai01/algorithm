#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2024-04-07

int count = 0;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
// 深度优先搜索
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
    // 被访问过或者不是陆地 直接返回
    if(visited[x][y] || grid[x][y] == 0) return;
    visited[x][y] = true;
    count++;
    // 遍历4个方向
    for(int i = 0; i < 4; i++){
        int Nextx = x + dir[i][0];
        int Nexty = y + dir[i][1];
        if(Nextx >= grid.size() || Nexty >= grid[x].size() || Nextx < 0 || Nexty < 0) continue;
        dfs(grid, visited, Nextx, Nexty);
    }
}


int maxAreaOfIsland(vector<vector<int>>& grid) {
    int result = 0;
    vector<vector<bool>> visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(!visited[i][j] && grid[i][j] == 1){
                count = 0;
                dfs(grid, visited, i, j);
                result = max(result, count);
            }
        }
    }

    return result;
}