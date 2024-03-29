#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int width = matrix[0].size();
    int height = matrix.size();

    int left = 0, right = width - 1;
    int up = 0, down = height - 1;

    while(true){
        for(int i = left; i <= right; i++){
            result.push_back(matrix[up][i]);
        }
        up++;
        if(up > down)
        break;

        for(int i = up; i <= down; i++){
            result.push_back(matrix[i][right]);
        }
        right--;
        if(right < left)
        break;

        for(int i = right; i >= left; i--){
            result.push_back(matrix[down][i]);
        }
        down--;
        if(down < up)
        break;

        for(int i = down; i >= up; i--){
            result.push_back(matrix[i][left]);
        }
        left++;
        if(left > right)
        break;
    }

    return result;


}