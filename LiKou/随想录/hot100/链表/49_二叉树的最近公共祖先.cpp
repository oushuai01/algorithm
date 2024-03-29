#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.21
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == q || root == p) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);


    if(left != nullptr && right != nullptr) return root;
    if(left == nullptr) return right;
    if(right == nullptr) return left;

    return nullptr;
    
}
