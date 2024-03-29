#include <iostream>
#include <vector>
#include <string>
//10.27

using namespace std;

const string lettersMap[10] = {
    "",          //0
    "",          //1
    "abc",       //2
    "def",       //3
    "ghi",       //4
    "jkl",       //5
    "mno",       //6
    "pqrs",      //7
    "tuv",       //8
    "wxyz",      //9
};

vector<string> result;
string path;

void letterTrack(string digits, int index){
    if(path.size() == digits.size()){
        result.push_back(path);
        return;
    }

    int letter_index = digits[index] - '0';   //得到他的索引
    string letter = lettersMap[letter_index];

    for(int i = 0; i < letter.size(); i++){
        path.push_back(letter[i]);
        letterTrack(digits, index + 1);
        path.pop_back();
    }
}


vector<string> letterCombinations(string digits) {
    if(digits.size() == 0){
        return result;
    }

    letterTrack(digits, 0);
    return result;
}


