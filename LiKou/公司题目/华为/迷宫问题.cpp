#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<vector<int>> temp;
void backtrack(vector<vector<int>>& grid, int x, int y){
    // 记录走过的路径
    grid[x][y] = 1;

    // 将路径放入容器
    temp.push_back({x,y});
    
    // 判断是否为最好的路径
    if(x == grid.size() - 1 && y == grid[0].size() - 1){
        if(result.empty() || temp.size() < result.size())
        result = temp;
    }

    if(y - 1 >= 0 && grid[x][y - 1] == 0)
    backtrack(grid,  x,     y - 1);
    if(x + 1 <= grid.size() && grid[x + 1][y] == 0)
    backtrack(grid,  x + 1, y);
    if(x - 1 >= 0 && grid[x - 1][y] == 0)
    backtrack(grid,  x - 1, y);
    if(y + 1 <= grid[0].size() && grid[x][y + 1] == 0)
    backtrack(grid,  x,     y + 1);
    temp.pop_back();
    grid[x][y] = 0;

}


int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
        cin >> grid[i][j];
    }
    backtrack(grid, 0, 0);
    for(auto itor : result){
        cout << "(" << itor[0] << "," << itor[1] << ")" << endl; 
    }

}
// 64 位输出请用 printf("%lld")