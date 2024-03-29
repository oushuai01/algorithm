/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-09 10:42:44
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-10 10:06:57
 * @FilePath: \algorithm\LiKou\随想录\二叉树\04_翻转二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//10.10
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

//递归遍历实现
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return root;
    
    swap(root->left, root->left);
    invertTree(root->left);
    invertTree(root->right);

    return root;
}


//层序遍历实现
TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> que;
    if(root != nullptr) que.push(root);

    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            if(node->left != nullptr || node->right != nullptr)
            swap(node->left, node->right);

            if(node->left != nullptr)  que.push(node->left);
            if(node->right != nullptr)  que.push(node->right);
        }
    }

    return root;
}
