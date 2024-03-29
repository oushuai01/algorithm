/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-22 15:32:10
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-22 15:32:30
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\25_翻转二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return nullptr;

    if(root->left) invertTree(root->left);
    if(root->right) invertTree(root->right);

    swap(root->left, root->right);

    return root;
}