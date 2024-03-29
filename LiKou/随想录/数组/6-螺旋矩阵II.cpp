#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n,vector<int>(n,0));
    int left = 0;
    int right = n-1;
    int top = 0;
    int low = n-1;
    int target = n * n;
    int count = 1;
    while(count <= target){
        // 从左往右
        for(int r = left; r <= right; r++) res[top][r] = count++;
        top++;
        // 从上往下
        for(int t = top; t <= low; t++) res[t][right] = count++;
        right--;
        // 从右往左
        for(int l = right; l >= left; l--) res[low][l] = count++;
        low--;
        // 从下往上
        for(int up = low; up >= top; up--) res[up][left] = count++;
        left++;
    }
    return res;
 
}

int main(){
    vector<vector<int>> vec = generateMatrix(3);
    for (auto &&v : vec)
    {
        for (auto &&i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        
    }
    
    return 0;
}
