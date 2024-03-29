#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;



vector<vector<int>> generate(int numRows) {
    if(numRows == 1)
    return  {{1}};
    vector<vector<int>> res = {{1}};
    vector<int> num;
    for(int i = 1; i < numRows; i++){
        for(int j = 1; j < i; j++){
            num.push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
        num.insert(num.begin(),1);
        num.push_back(1);
        res.push_back(num);
        num.clear();
    }
    return res;
}

int main(){
    int numRows = 6;
    vector<vector<int>> res = generate(numRows);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}