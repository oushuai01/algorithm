/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-25 14:19:11
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-25 14:27:03
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\26_对称二叉树.cpp
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

bool campare(TreeNode* left, TreeNode* right){
    if(left != nullptr && right == nullptr) return false;
    else if(left == nullptr && right != nullptr) return false;
    else if(left == nullptr && right == nullptr) return true;
    else if(left->val != right->val) return false;

    bool outside = campare(left->left, right->right);
    bool inside = campare(left->right, right->left);
    bool isSame = outside && inside;

    return isSame;
}

bool isSymmetric(TreeNode* root){
    if(root == nullptr) return false;
    return campare(root->left, root->right);
}

