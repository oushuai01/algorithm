#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> vc;
    int right = matrix[0].size() - 1;
    int down = matrix.size() - 1;
    int left = 0;
    int up = 0;
    while (true)
    {
        for(int i = left; i <= right; i++){
            vc.push_back(matrix[up][i]);
        }
        if(up > down) break;
        up++;
        for(int i = up; i <= down; i++){
            vc.push_back(matrix[i][right]);
        }
        if(right < left) break;
        right--;
        for(int i = right; i >= left; i--){
            vc.push_back(matrix[down][i]);
        }
        if(down < up) break;
        down--;
        for(int i = down; i >= up; i--){
            vc.push_back(matrix[i][left]);
        }
        if(left > right) break;
        left++;
    }
    return vc;

}

int main()
{
    vector<vector<int>> vc = {{1,2,3,8},{4,5,6,10},{7,8,9,15}};
    vector<int> result = spiralOrder(vc);
    for(vector<int>::iterator it = result.begin(); it < result.end(); it++){
        cout << *it << " ";
    }

    return 0;
}
