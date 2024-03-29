#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.08  

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int maxLine(TreeNode* root, int& maxline_){
    if(root == nullptr) return 0;

    int left = maxLine(root->left, maxline_);
    int right = maxLine(root->right, maxline_);

    // 记录最大直径
    maxline_ = max(maxline_, left + right);
    return max(left, right) + 1;
}


int diameterOfBinaryTree(TreeNode* root) {
    if(root == nullptr) return 0;

    int maxline = 0;
    maxLine(root, maxline);
    return maxline;
}