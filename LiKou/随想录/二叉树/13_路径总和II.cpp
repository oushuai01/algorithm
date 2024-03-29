//10.14

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};



vector<vector<int>> res;

void traversal(TreeNode* root, vector<int>& vec, int targetSum){
    if(!root->left && !root->right && targetSum == 0){
        res.push_back(vec);
        return;
    }


    if(root->left){
        vec.push_back(root->left->val);
        traversal(root->left, vec, targetSum - root->left->val);
        vec.pop_back();                  //回溯
    }

    if(root->right){
        vec.push_back(root->right->val);
        traversal(root->right, vec, targetSum - root->right->val);
        vec.pop_back();                 //回溯
    }

    return;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> vec;
    if(root != nullptr){
        vec.push_back(root->val);
        traversal(root, vec, targetSum - root->val);
    }

    return res;
    
}