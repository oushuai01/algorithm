/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-26 14:16:56
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-26 14:39:15
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\32_二叉树的右视图.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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

// 可以递归实现
vector<int> result;
void backTraversal(TreeNode* root, int depth){
    if(root == nullptr) return;

    if(result.size() == depth){
        result.push_back(root->val);
    }

    backTraversal(root->right, depth + 1);
    backTraversal(root->left, depth + 1);

    return;
}

vector<int> rightSideView(TreeNode* root) {
    if(root == nullptr) return result;

    backTraversal(root, 0);

    return result;
}


// 可以用层序遍历 queue实现
vector<int> rightSideView_(TreeNode* root){
    vector<int> res;
    if(root == nullptr) return res;

    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        int size_ = que.size();

        for(int i = 0; i < size_; i++){
            TreeNode* temp = que.front();
            que.pop();
            
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);

            if(i == (size_ - 1)) res.push_back(temp->val);
        }
    }

    return res;
}


