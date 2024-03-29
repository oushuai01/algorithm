#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int han = obstacleGrid.size();
    int lie = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1 || obstacleGrid[han - 1][lie - 1] == 1)
       return 0;

    vector<vector<int>> dp(han,vector<int>(lie,0));

    for(int i = 0; i < han; ++i){
        if(obstacleGrid[i][0] == 1)
        break;
        else
        dp[i][0] = 1;
    }

     for(int j = 0; j < lie; ++j){
        if(obstacleGrid[0][j] == 1)
        break;
        else
        dp[0][j] = 1;
    }

    for(int i = 1; i < han; i++){
        for(int j = 1; j < lie; j++){
            if(obstacleGrid[i][j] == 1)
            continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[han-1][lie-1];
}


int main(){
    vector<vector<int>> ob = {{0,0},{1,1},{0,0}};
    cout << uniquePathsWithObstacles(ob);
}