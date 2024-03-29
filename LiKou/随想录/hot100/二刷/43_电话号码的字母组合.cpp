#include <iostream>
#include <vector>
using namespace std;

// 2024-03-29

class Solution {
public:
    string path;
    vector<string> result;
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void backTrack(string digits, int index){
        if(path.size() == digits.size()){
            result.push_back(path);
            return;
        }
        
        // 得到 digits 数字
        int letter_index = digits[index] - '0';
        string letter = letterMap[letter_index];


        for(int i = 0; i < letter.size(); i++){
            path.push_back(letter[i]);
            backTrack(digits, index + 1);
            path.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;

        backTrack(digits, 0);
        return result;
    }
};