#include <iostream>
#include <vector>
using namespace std;
//10.18
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == q || root == p || root == nullptr) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p ,q);
    TreeNode* right = lowestCommonAncestor(root->right, p ,q);

    if(left != nullptr && right != nullptr) return root;
    if(left != nullptr) return left;
    if(right != nullptr) return right;

    return nullptr;
}