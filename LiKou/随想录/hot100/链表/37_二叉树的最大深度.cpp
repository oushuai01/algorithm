/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-06 15:45:47
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-06 15:54:09
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\37_二叉树的最大深度.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int maxDepth(TreeNode* root){
    if(root == nullptr) return 0;
    queue<TreeNode*> que;
    int size_ = 0;
    int depth = 0;
    que.push(root);

    while(!que.empty()){
        size_ = que.size();
        for(int i = 0; i < size_; i++){
            TreeNode* temp = que.front();
            que.pop();
            if(temp->left != nullptr) que.push(temp->left);
            if(temp->right != nullptr) que.push(temp->right);
        }
        depth++;
    }

    return depth;
}