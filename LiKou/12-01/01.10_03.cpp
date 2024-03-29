#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if((mat.size() * mat[0].size()) != (r * c))
    return mat;
    int han = 0;
    int lie = 0;
    vector<vector<int>> res(r,vector<int>(c));
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            res[han][lie] = mat[i][j];
            lie++;
            if(lie == c){
                han++;
                lie = 0;
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> mat = {{1,2},{3,4}};
    int  r = 1, c = 4;
    vector<vector<int>> res = matrixReshape(mat,r,c);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}