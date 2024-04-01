#include <iostream>
#include <vector>
using namespace std;

vector<string> path;
void backTrack(string str, int left, int right){
    // 如果左括号小于0 或者左括号大于右括号(说明前面是右括号--无效) 
    // 出现类似 ()) )) 这种格式都是错误的不用再继续了
    if(left < 0 || left > right) return;

    if(left == 0 && right == 0) path.push_back(str);

    // 优先搜索左括号
    backTrack(str + "(", left - 1, right);
    backTrack(str + ")", left, right - 1);
}
vector<string> generateParenthesis(int n) {
    backTrack("", n, n);
    return path;
}