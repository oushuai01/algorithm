#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* root, int dep){
    if(root == nullptr) return dep;

    int left = dfs(root->left, dep + 1);
    int right = dfs(root->right, dep + 1);

    return max(left, right);
}


int maxDepth(TreeNode* root) {
    return dfs(root, 0);
}
