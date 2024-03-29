#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};





vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == nullptr) return result;

    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        int size_ = que.size();
        vector<int> vec;

        for(int i = 0; i < size_; i++){
            TreeNode* temp = que.front();
            que.pop();
            
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
            vec.push_back(temp->val);
        }
        result.push_back(vec);
    }

    return result;


}
