/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-09 19:06:35
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-09 19:10:23
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\41_二叉树的层序遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.09
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


vector<vector<int>> levelOrder(TreeNode* root){
    if(root == nullptr) return {{}};
    vector<vector<int>> result;
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

