#include <iostream>
#include <vector>
using namespace std;


bool backTrack(vector<vector<char>>& board, string word, int i, int j, int k){
    if(i < 0 || i > board.size() || j < 0 || j > board[0].size() || board[i][j] != word[k])
    return false;
    if(k == word.size() - 1) return true;

    board[i][j] = '\0';
    bool res = backTrack(board, word, i + 1, j, k + 1) || backTrack(board, word, i, j + 1, k + 1) \
                || backTrack(board, word, i + 1, j - 1, k + 1) || backTrack(board, word, i - 1, j, k + 1);

    board[i][j] = word[k];

    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word.size() == 0 || board.size() == 0) return false;

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(backTrack(board, word, i, j, 0)) return true;
        }
    }

    return false;
}