/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-25 15:13:04
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-25 15:22:48
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\30_验证二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 中序遍历完看是否为有序

long long max_val = LONG_LONG_MIN;

bool midTraversal(TreeNode* root){
    if(root == nullptr) return true;

    bool left = midTraversal(root->left);

    if(max_val < root->val) max_val = root->val;
    else return false;

    bool right = midTraversal(root->right);

    return left && right;
}



bool isValidBST(TreeNode* root){
    if(root == nullptr) return false;
    else
    return midTraversal(root);
}
