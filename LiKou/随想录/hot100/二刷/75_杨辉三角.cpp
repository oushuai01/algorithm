#include <iostream>
#include <vector>
using namespace std;

// 2024-04-09
    
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    if(numRows == 0) return result;
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) result[i].push_back(1);
            else{
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
        }
    }

    return result;
}

// 
vector<vector<int>> generate_(int numRows) {
        if(numRows == 1) return {{1}};
    if(numRows == 2) return {{1},{1,1}};

    vector<vector<int>> result;
    result.push_back({1});
    result.push_back({1, 1});
    

    for(int i = 2; i < numRows; i++){
        vector<int> temp(result[i - 1].size() + 1);
        // 前补1
        temp[0] = 1;
        for(int j = 1; j < result[i - 1].size(); j++){
            temp[j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        // 后补1
        temp[result[i - 1].size()] = 1;
        result.push_back(temp);
    }

    return result;
}