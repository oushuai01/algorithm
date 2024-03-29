#include <iostream>
#include <vector>
using namespace std;
//10.16
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
//前中后序都可以实现
 TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
    if(root1 == nullptr) return root2;
    if(root2 == nullptr) return root1;

    //合并
    root1->val += root2->val;                                    //中

    root1->left = mergeTrees(root1->left, root2->left);          //左
    root1->right = mergeTrees(root1->right, root2->right);       //右

    return root1;
 }