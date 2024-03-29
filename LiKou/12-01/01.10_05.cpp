#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<map<char,int>>  han(9);
    vector<map<char,int>>  lie(9);
    vector<map<char,int>>  row(9);
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == '.')
            continue;
            else{
                han[i][board[i][j]]++;
                lie[j][board[i][j]]++;
                //判断为哪个九宫格
                int h = i / 3;
                int l = j / 3;
                int index = 3 * (h) + l;
                row[index][board[i][j]]++;
                if(han[i][board[i][j]] > 1 || lie[j][board[i][j]] > 1 || row[index][board[i][j]] > 1)
                return false;
            }
        }
    }
    return true;

}

int main(){

}